#include <SFML/OpenGL.hpp>

#include "TextBox.hpp"
#include "Theme.hpp"

#define BLINK_PERIOD 1.f

namespace gui
{

	TextBox::TextBox(float width) :
		m_box(Box::Input),
		m_cursor_pos(0),
		m_max_length(-1)
	{
		m_box.setSize(width, Theme::getBoxHeight());

		int offset = Theme::borderSize + Theme::PADDING;
		m_text.setFont(Theme::getFont());
		m_text.setPosition(offset, offset);
		m_text.setColor(Theme::input.textColor);
		m_text.setCharacterSize(Theme::textSize);

		// Build cursor
		m_cursor.setPosition(offset, offset);
		m_cursor.setSize(sf::Vector2f(1.f, Theme::getLineSpacing()));
		m_cursor.setFillColor(Theme::input.textColor);
		setCursor(0);

		setSize(m_box.getSize());
	}


	void TextBox::setText(const sf::String& string)
	{
		m_text.setString(string);
		setCursor(string.getSize());
	}


	const sf::String& TextBox::getText() const
	{
		return m_text.getString();
	}



	void TextBox::setCursor(size_t index)
	{
		if (index <= m_text.getString().getSize())
		{
			m_cursor_pos = index;

			float padding = Theme::borderSize + Theme::PADDING;
			m_cursor.setPosition(m_text.findCharacterPos(index).x, padding);
			m_cursor_timer.restart();

			if (m_cursor.getPosition().x > getSize().x - padding)
			{
				// Shift text on left
				float diff = m_cursor.getPosition().x - getSize().x + padding;
				m_text.move(-diff, 0);
				m_cursor.move(-diff, 0);
			}
			else if (m_cursor.getPosition().x < padding)
			{
				// Shift text on right
				float diff = padding - m_cursor.getPosition().x;
				m_text.move(diff, 0);
				m_cursor.move(diff, 0);
			}

			float text_width = m_text.getLocalBounds().width;
			if (m_text.getPosition().x < padding
				&& m_text.getPosition().x + text_width < getSize().x - padding)
			{
				float diff = (getSize().x - padding) - (m_text.getPosition().x + text_width);
				m_text.move(diff, 0);
				m_cursor.move(diff, 0);
				// If text is smaller than the textbox, force align on left
				if (text_width < (getSize().x - padding * 2))
				{
					diff = padding - m_text.getPosition().x;
					m_text.move(diff, 0);
					m_cursor.move(diff, 0);
				}
			}
		}
	}


	size_t TextBox::getCursor() const
	{
		return m_cursor_pos;
	}


	void TextBox::onKeyPressed(sf::Keyboard::Key key)
	{
		switch (key)
		{
		case sf::Keyboard::Left:
			setCursor(m_cursor_pos - 1);
			break;

		case sf::Keyboard::Right:
			setCursor(m_cursor_pos + 1);
			break;

		case sf::Keyboard::BackSpace:
			// Erase character before cursor
			if (m_cursor_pos > 0)
			{
				sf::String string = m_text.getString();
				string.erase(m_cursor_pos - 1);
				m_text.setString(string);

				setCursor(m_cursor_pos - 1);
			}
			break;

		case sf::Keyboard::Delete:
			// Erase character after cursor
			if (m_cursor_pos < m_text.getString().getSize())
			{
				sf::String string = m_text.getString();
				string.erase(m_cursor_pos);
				m_text.setString(string);

				setCursor(m_cursor_pos);
			}
			break;

		case sf::Keyboard::Home:
			setCursor(0);
			break;

		case sf::Keyboard::End:
			setCursor(m_text.getString().getSize());
			break;

		case sf::Keyboard::Return:
			triggerCallback();
			break;

		default:
			break;
		}
	}


	void TextBox::onMousePressed(float x, float y)
	{
		for (int i = m_text.getString().getSize(); i >= 0; --i)
		{
			// Place cursor after the character under the mouse
			sf::Vector2f glyph_pos = m_text.findCharacterPos(i);
			if (glyph_pos.x <= x)
			{
				setCursor(i);
				break;
			}
		}
	}


	void TextBox::onTextEntered(sf::Uint32 unicode)
	{
		if (unicode > 30 && (unicode < 127 || unicode > 159))
		{
			sf::String string = m_text.getString();
			if (m_max_length == -1 || (int)string.getSize() < m_max_length)
			{
				// Insert character in string at cursor position
				string.insert(m_cursor_pos, unicode);
				m_text.setString(string);

				setCursor(m_cursor_pos + 1);
			}
		}
	}


	void TextBox::onStateChanged(State state)
	{
		m_box.applyState(state);
	}


	void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(m_box, states);

		// Crop the text with GL Scissor
		glEnable(GL_SCISSOR_TEST);
		sf::Vector2f pos = getAbsolutePosition();
		glScissor(pos.x + Theme::borderSize, target.getSize().y - (pos.y + getSize().y), getSize().x, getSize().y);
		target.draw(m_text, states);

		glDisable(GL_SCISSOR_TEST);

		// Show cursor if focused
		if (isFocused())
		{
			// Make it blink
			float timer = m_cursor_timer.getElapsedTime().asSeconds();
			if (timer >= BLINK_PERIOD)
				m_cursor_timer.restart();

			// Updating in the drawing method, deal with it
			sf::Color color = Theme::input.textColor;
			color.a = 255 - (255 * timer / BLINK_PERIOD);
			m_cursor.setFillColor(color);

			target.draw(m_cursor, states);
		}
	}

}
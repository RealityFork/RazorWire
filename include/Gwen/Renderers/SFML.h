/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_RENDERERS_SFML_H
#define GWEN_RENDERERS_SFML_H
#include "Gwen/Gwen.h"
#include "Gwen/BaseRender.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

namespace Gwen 
{
	namespace Renderer 
	{

		class SFML : public Gwen::Renderer::Base
		{
			public:

				SFML( sf::RenderTarget& target );
				~SFML();

				virtual void SetDrawColor(Gwen::Color color);

				virtual void DrawFilledRect( Gwen::Rect rect );

				virtual void LoadFont( Gwen::Font* pFont );
				virtual void FreeFont( Gwen::Font* pFont );
				virtual void RenderText( Gwen::Font* pFont, Gwen::Point pos, const Gwen::UnicodeString& text );
				virtual Gwen::Point MeasureText( Gwen::Font* pFont, const Gwen::UnicodeString& text );
	
				void StartClip();
				void EndClip();
			
				void DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect pTargetRect, float u1=0.0f, float v1=0.0f, float u2=1.0f, float v2=1.0f );
				void LoadTexture( Gwen::Texture* pTexture );
				void FreeTexture( Gwen::Texture* pTexture );
				Gwen::Color PixelColour( Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color& col_default );

			protected:

				sf::RenderTarget&	m_Target;
				sf::Color			m_Color;

		};
	}
}
#endif

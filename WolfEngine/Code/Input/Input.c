#include "Input.h"
Keys Input_Keys;

void Input_Update(SDL_Event * eventHandler)
{
	if (eventHandler->type == SDL_KEYDOWN)
	{
		switch (eventHandler->key.keysym.sym)
		{
			//Letter Keys
			case SDLK_a:
				Input_Keys.A = 1;
				break;
			case SDLK_b:
				Input_Keys.B = 1;
				break;
			case SDLK_c:
				Input_Keys.C = 1;
				break;
			case SDLK_d:
				Input_Keys.D = 1;
				break;
			case SDLK_e:
				Input_Keys.E = 1;
				break;
			case SDLK_f:
				Input_Keys.F = 1;
				break;
			case SDLK_g:
				Input_Keys.G = 1;
				break;
			case SDLK_h:
				Input_Keys.H = 1;
				break;
			case SDLK_i:
				Input_Keys.I = 1;
				break;
			case SDLK_j:
				Input_Keys.J = 1;
				break;
			case SDLK_k:
				Input_Keys.K = 1;
				break;
			case SDLK_l:
				Input_Keys.L = 1;
				break;
			case SDLK_m:
				Input_Keys.M = 1;
				break;
			case SDLK_n:
				Input_Keys.N = 1;
				break;
			case SDLK_o:
				Input_Keys.O = 1;
				break;
			case SDLK_p:
				Input_Keys.P = 1;
				break;
			case SDLK_q:
				Input_Keys.Q = 1;
				break;
			case SDLK_r:
				Input_Keys.R = 1;
				break;
			case SDLK_s:
				Input_Keys.S = 1;
				break;
			case SDLK_t:
				Input_Keys.T = 1;
				break;
			case SDLK_u:
				Input_Keys.U = 1;
				break;
			case SDLK_v:
				Input_Keys.V = 1;
				break;
			case SDLK_w:
				Input_Keys.W = 1;
				break;
			case SDLK_x:
				Input_Keys.X = 1;
				break;
			case SDLK_y:
				Input_Keys.Y = 1;
				break;
			case SDLK_z:
				Input_Keys.Z = 1;
				break;
			//Bottom row
			case SDLK_LSHIFT:
				Input_Keys.LeftShift = 1;
				break;
			case SDLK_LCTRL:
				Input_Keys.LeftControl = 1;
				break;
			case SDLK_LALT:
				Input_Keys.LeftAlt = 1;
				break;
			case SDLK_SPACE:
				Input_Keys.Space = 1;
				break;
			case SDLK_RALT:
				Input_Keys.RightAlt = 1;
				break;
			case SDLK_RCTRL:
				Input_Keys.RightControl = 1;
				break;
			case SDLK_RSHIFT:
				Input_Keys.RightShift = 1;
				break;
			
			//Arrow Keys
			case SDLK_UP:
				Input_Keys.ArrowUp = 1;
				break;
			case SDLK_LEFT:
				Input_Keys.ArrowLeft = 1;
				break;
			case SDLK_DOWN:
				Input_Keys.ArrowDown = 1;
				break;
			case SDLK_RIGHT:
				Input_Keys.ArrowRight = 1;
				break;

			//Other Keys
			case SDLK_RETURN:
				Input_Keys.Return = 1;
				break;
			case SDLK_RETURN2:
				Input_Keys.KeypadReturn = 1;
				break;
			case SDLK_TAB:
				Input_Keys.Tab = 1;
				break;
		}
	}
	if (eventHandler->type == SDL_KEYUP)
	{
		switch (eventHandler->key.keysym.sym)
		{
			//Letter Keys
			case SDLK_a:
				Input_Keys.A = 0;
				break;
			case SDLK_b:
				Input_Keys.B = 0;
				break;
			case SDLK_c:
				Input_Keys.C = 0;
				break;
			case SDLK_d:
				Input_Keys.D = 0;
				break;
			case SDLK_e:
				Input_Keys.E = 0;
				break;
			case SDLK_f:
				Input_Keys.F = 0;
				break;
			case SDLK_g:
				Input_Keys.G = 0;
				break;
			case SDLK_h:
				Input_Keys.H = 0;
				break;
			case SDLK_i:
				Input_Keys.I = 0;
				break;
			case SDLK_j:
				Input_Keys.J = 0;
				break;
			case SDLK_k:
				Input_Keys.K = 0;
				break;
			case SDLK_l:
				Input_Keys.L = 0;
				break;
			case SDLK_m:
				Input_Keys.M = 0;
				break;
			case SDLK_n:
				Input_Keys.N = 0;
				break;
			case SDLK_o:
				Input_Keys.O = 0;
				break;
			case SDLK_p:
				Input_Keys.P = 0;
				break;
			case SDLK_q:
				Input_Keys.Q = 0;
				break;
			case SDLK_r:
				Input_Keys.R = 0;
				break;
			case SDLK_s:
				Input_Keys.S = 0;
				break;
			case SDLK_t:
				Input_Keys.T = 0;
				break;
			case SDLK_u:
				Input_Keys.U = 0;
				break;
			case SDLK_v:
				Input_Keys.V = 0;
				break;
			case SDLK_w:
				Input_Keys.W = 0;
				break;
			case SDLK_x:
				Input_Keys.X = 0;
				break;
			case SDLK_y:
				Input_Keys.Y = 0;
				break;
			case SDLK_z:
				Input_Keys.Z = 0;
				break;
				//Bottom row
			case SDLK_LSHIFT:
				Input_Keys.LeftShift = 0;
				break;
			case SDLK_LCTRL:
				Input_Keys.LeftControl = 0;
				break;
			case SDLK_LALT:
				Input_Keys.LeftAlt = 0;
				break;
			case SDLK_SPACE:
				Input_Keys.Space = 0;
				break;
			case SDLK_RALT:
				Input_Keys.RightAlt = 0;
				break;
			case SDLK_RCTRL:
				Input_Keys.RightControl = 0;
				break;
			case SDLK_RSHIFT:
				Input_Keys.RightShift = 0;
				break;

				//Arrow Keys
			case SDLK_UP:
				Input_Keys.ArrowUp = 0;
				break;
			case SDLK_LEFT:
				Input_Keys.ArrowLeft = 0;
				break;
			case SDLK_DOWN:
				Input_Keys.ArrowDown = 0;
				break;
			case SDLK_RIGHT:
				Input_Keys.ArrowRight = 0;
				break;

				//Other Keys
			case SDLK_RETURN:
				Input_Keys.Return = 0;
				break;
			case SDLK_RETURN2:
				Input_Keys.KeypadReturn = 0;
				break;
			case SDLK_TAB:
				Input_Keys.Tab = 0;
				break;
		}
	}
}
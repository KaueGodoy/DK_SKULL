#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <math.h>
#include <windows.h>

#define ESC 27
	
struct Tmain{
	int tam_main;
};

// ---------------------------------------------------> variaveis globais <-------------------------------------------

	// resolucao tela
	int telaX_glb, telaY_glb;
	int telainX, telainY;
	
// ------------------------------------------------------> botoes <------------------------------------------------	
	
	// botao tamanho
	int btnX_glb, btnY_glb;
	
	// botao posicao
	int btn_jogar_X;
	int btn_jogar_Y;

	int btn_creditos_X;
	int btn_creditos_Y;
	
	int btn_sair_X;
	int btn_sair_Y;
	
	int btn_voltar_X;
	int btn_voltar_Y;
	
	int btn_menu_X;
	int btn_menu_Y;
	
	int btn_sair_go_X;
	int btn_sair_go_Y;
	
	int btn_retry_X;
	int btn_retry_Y;
	
	// botao imagem vetor
  	int tam;
  	
  	// menu
	void *menu_bg;
	void *btn_jogar, *btn_jogar_hover;
	void *btn_creditos, *btn_creditos_hover;
	void *btn_sair, *btn_sair_hover;
	int menu_return;
	
	// creditos
	void *btn_voltar, *btn_voltar_hover;
	
	// game over
	void *btn_menu, *btn_menu_hover;
	void *btn_sair_go,*btn_sair_go_hover;
	void *btn_retry, *btn_retry_hover;
	
	// intro
	void *btn_skip, *intro_bg;
	
	// end
	void *end_bg;
	
// -------------------------------------------------------------> Game <----------------------------------------------------
	
	// resolucao tela
	int telaX, telaY; 
	int zeroX, zeroY;
	
// -----------------------------------------------------------> vetor img <------------------------------------------------------

	// player sprite / mascara 
	void *S;
	void *SM;
	
	// boss sprite / mascara
	void *B;
	void *BM;
	
	// floor sprite 
	void *F;
	
	// spell sprite
	void *Sp;
	void *SpM;
	
	// frag sprite
	void *Fr;
	void *FrM;
	
	// background - fase 1
	void *BG;
	
	// HP sprite
	void *HpS;
	void *HpM;
	
	// dash sprite
	void *D2S;
	void *D2M;
	void *D1S;
	void *D1M;
	void *D0S;
	void *D0M;
	
	// time stop
	void *TS;
	void *TSM;
	
	// frag 2 
	void *Fr2;
	void *FrM2;
	
// ------------------------------------------------------> sprite tam <--------------------------------------------------
	
	// player sprite img
	int player_x, player_y;
	int player_passoX, player_passoY;
	
	// boss sprite img
	int boss_x, boss_y;
	int boss_passoX, boss_passoY;
	
	// floor sprite img
	int floor_x, floor_y;
	int floor_passoX, floor_passoY;
	int floor_vx, floor_vy;
	int fmov_x, fmov_y;
	int floor_effect;
	
	// spell sprite img
	int spell_x, spell_y;
	int spell_passoX, spell_passoY;
	int Sp_cont;
	
	// spell 2
	int spell_2_passoX, spell_2_passoY;
	int Sp_2x_min, Sp_2x_max;
	int Sp_2y_min, Sp_2y_max;

	// background img - fase 1
	int bg_1x, bg_1y;
	
	// frag sprite img
	int frag_x, frag_y;
	int frag_passoX, frag_passoY;
	int frag_vx, frag_vy;
		
	// hp sprite img
	int hp_x, hp_y;
	int hp_qtd;
	int hp_col;
	
	// pulo
	int pulo;
	int tam_pulo;
	int teto_b;
	int caindo;
	int pres_esp;
	
	// dash sprite
	int dash_x, dash_y;
	
	// dash / mov speed
	int pres_shift;
	int dash_qtd;
	int dash_cd;
	int cd_timer;
	
	// time stop 
	int time_stop_x, time_stop_y;
	int time_stop_qtd;
	
// -----------------------------------------------------> posicao/spawn <------------------------------------	
	
	// player - spawn
	int px, py;
	
	// boss - spawn
	int bx, by;
	int bx_min, bx_max;
	int by_min, by_max;
	
	// flor - spawn
	int fx, fy;
	
	// pulo/teto
	int teto_h, teto_l;
	
	// spell - spawn
	int Spx, Spy;
	int Sp_2x, Sp_2y;
	
	// frag - spawn
	int fr_x, fr_y;
	int frag_qtd;
	int frag_qtd_obt;
	
	// frag 2 - spawn
	int fr_2x, fr_2y;
	int frag_2_qtd;
	int frag_2_qtd_obt;
	
	// time stop - spawn
	int TS_x, TS_y;
	
	// HP - spawn
	int hpx, hpy;
	
	// dash - spawn
	int dashX, dashY;
	
	// fps
	unsigned long long gt1, gt2;

	// funcoes
	void Menu();
	void Intro();
	void Game();
	void Fase_2();
	void Level_3();
	void End();
	void Game_Over();
	void Creditos();

int main(){
	
// ----------------------------------------> variaveis globais <-------------------------------------------
	
	//tela
	telaX_glb = 1280;
	telaY_glb = 720;
	telainX = 0;
	telainY = 0;
	
	// botao tamanho
	btnX_glb = 200;
	btnY_glb = 80;

	// tela gráfica
	initwindow(telaX_glb, telaY_glb, "DK_Skull", telainX, telainY);	
	gt1 = GetTickCount();  
	// menu
	Menu();
	
	// fecha tela grafica
	closegraph();	
  	return 0; 
}

// ------------------------------------------------> menu <---------------------------------------------

void Menu(){
	bool Fim = false;
  	int pg = 1;
  	POINT P;
  	HWND janela;
  	
  	// botoes posicao
  	btn_jogar_X = 540;
	btn_jogar_Y = 250;

	btn_creditos_X = 540;
	btn_creditos_Y = 350;
	
	btn_sair_X = 540;
	btn_sair_Y = 450;
	
	menu_return = 1;
  	
// Som Menu
//	mciSendString("open .\\sons\\intro.mp3 type MPEGVideo alias intro", NULL, 0, 0);
 	mciSendString("open .\\sons\\jump_11.mp3 type MPEGVideo alias jump", NULL, 0, 0);
 	mciSendString("open .\\sons\\intro.mp3 type MPEGVideo alias intro", NULL, 0, 0);
 	mciSendString("open .\\sons\\click26.mp3 type MPEGVideo alias click", NULL, 0, 0);
	
 	mciSendString("play intro repeat", NULL, 0, 0); // reproduz o som
 	
// botoes selecionados
  	bool btn_jogar_hover_bool = false;
  	bool btn_creditos_hover_bool = false;
  	bool btn_sair_hover_bool = false;
  	
// --------------------------------------------> imagens <------------------------------------------------------
	
// background imagem
  	tam = imagesize(0, 0, telaX_glb-1, telaY_glb-1);
  	menu_bg = malloc(tam);
  	readimagefile("image/menu/menu_bg.bmp", 0, 0, telaX_glb-1, telaY_glb-1);
  	getimage(0, 0, telaX_glb-1, telaY_glb-1, menu_bg);
  	
// botoes
  	cleardevice();
  	// jogar
  	tam = imagesize(0, 0, btnX_glb-1, btnY_glb-1);
   	btn_jogar = malloc(tam);
  	readimagefile("image/menu/jogar.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_jogar);
	
	btn_jogar_hover = malloc(tam);
  	readimagefile("image/menu/jogar_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_jogar_hover);
		
	// creditos
  	btn_creditos = malloc(tam);
  	readimagefile("image/menu/creditos.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_creditos);
	
	btn_creditos_hover = malloc(tam);
  	readimagefile("image/menu/creditos_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_creditos_hover);
  	
	// sair
	btn_sair = malloc(tam);
  	readimagefile("image/menu/sair.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair);	
  	
  	btn_sair_hover = malloc(tam);
  	readimagefile("image/menu/sair_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair_hover);	
	
	janela = GetForegroundWindow(); 
	
	while (!Fim){
		if (pg == 1) pg = 2; else pg = 1;
    	setactivepage(pg);
    	putimage(0, 0, menu_bg, COPY_PUT);
    	
    // botao sprite
    
    	// jogar 
        if (btn_jogar_hover_bool)
      		putimage(btn_jogar_X, btn_jogar_Y, btn_jogar_hover, COPY_PUT);
      		
    	else
     		putimage(btn_jogar_X, btn_jogar_Y, btn_jogar, COPY_PUT);
     	
     	// creditos
        if (btn_creditos_hover_bool)
      		putimage(btn_creditos_X, btn_creditos_Y, btn_creditos_hover, COPY_PUT); 
    	else
     		putimage(btn_creditos_X, btn_creditos_Y, btn_creditos, COPY_PUT);
     	
     	// sair 
     	if (btn_sair_hover_bool)
      		putimage(btn_sair_X, btn_sair_Y, btn_sair_hover, COPY_PUT); 
    	else
     		putimage(btn_sair_X, btn_sair_Y, btn_sair, COPY_PUT);
     	
		setvisualpage(pg);
		
	// mouse hovering	
		if (GetCursorPos(&P)) 
     	 	if (ScreenToClient(janela, &P)){		
		//jogar
        btn_jogar_hover_bool = false; 
        if (btn_jogar_X <= P.x && P.x <= btn_jogar_X+btnX_glb-1 && btn_jogar_Y <= P.y && P.y <= btn_jogar_Y+btnY_glb-1)
          btn_jogar_hover_bool = true;
		
		//creditos
        btn_creditos_hover_bool = false; 
        if (btn_creditos_X <= P.x && P.x <= btn_creditos_X+btnX_glb-1 && btn_creditos_Y <= P.y && P.y <= btn_creditos_Y+btnY_glb-1)
          btn_creditos_hover_bool = true;
        
		// sair
		btn_sair_hover_bool = false; 
        if (btn_sair_X <= P.x && P.x <= btn_sair_X+btnX_glb-1 && btn_sair_Y <= P.y && P.y <= btn_sair_Y+btnY_glb-1)
          btn_sair_hover_bool = true;

		if(GetKeyState(VK_LBUTTON)&0x80) {
          	// jogar botao
        	if (btn_jogar_X <= P.x && P.x <= btn_jogar_X+btnX_glb-1 && btn_jogar_Y <= P.y && P.y <= btn_jogar_Y+btnY_glb-1)
            	Intro();
            	//Level_3();
            // creditos botao
        	if (btn_creditos_X <= P.x && P.x <= btn_creditos_X+btnX_glb-1 && btn_creditos_Y <= P.y && P.y <= btn_creditos_Y+btnY_glb-1)
            	Creditos(); 
            // sair botao
		 	else if (btn_sair_X <= P.x && P.x <= btn_sair_X+btnX_glb-1 && btn_sair_Y <= P.y && P.y <= btn_sair_Y+btnY_glb-1)
		 		Fim = true;
		}
			}
	}
}


// --------------------------------------------------> intro <-----------------------------------------------

void Intro(){
	bool Fim = false;
  	int pg = 1;
  	POINT P;
  	HWND janela;
	
	// background imagem
  	tam = imagesize(0, 0, telaX_glb-1, telaY_glb-1);
  	intro_bg = malloc(tam);
  	readimagefile("image/intro/intro_bg.bmp", 0, 0, telaX_glb-1, telaY_glb-1);
  	getimage(0, 0, telaX_glb-1, telaY_glb-1, intro_bg);
    	
	// botoes
  	cleardevice();
  	
	// skip (barra espaco)
  	tam = imagesize(0, 0, btnX_glb-1, btnY_glb-1);
  	btn_skip = malloc(tam);
  	readimagefile("image/menu/btn_skip.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_skip);
  			
	janela = GetForegroundWindow(); 
	
	while (!Fim){
		if (pg == 1) pg = 2; else pg = 1;
    	setactivepage(pg);
    	putimage(0, 0, intro_bg, COPY_PUT);
    	
		setvisualpage(pg);
		
		// skip -  tecla espaco
		if(GetKeyState(32)&0x80){
            Game();
			Fim = true;
		}  
	}
}


// --------------------------------------------------> end <---------------------------------------------

void End(){
	bool Fim = false;
  	int pg = 1;
  	POINT P;
  	HWND janela;
  	  	
  	// botoes posicao
	btn_sair_X = 540;
	btn_sair_Y = 450;
	
	bool btn_sair_hover_bool = false;
	
	// background imagem
  	tam = imagesize(0, 0, telaX_glb-1, telaY_glb-1);
  	end_bg = malloc(tam);
  	readimagefile("image/end/end_bg.bmp", 0, 0, telaX_glb-1, telaY_glb-1);
  	getimage(0, 0, telaX_glb-1, telaY_glb-1, end_bg);
  	
	// botoes
  	cleardevice();
  	 
	   	
  	// sair
  	tam = imagesize(0, 0, btnX_glb-1, btnY_glb-1);
	btn_sair = malloc(tam);
  	readimagefile("image/menu/sair.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair);	
  	
  	btn_sair_hover = malloc(tam);
  	readimagefile("image/menu/sair_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair_hover);	
		
	janela = GetForegroundWindow(); 
	
	while (!Fim){
		if (pg == 1) pg = 2; else pg = 1;
    	setactivepage(pg);
    
		// background imagem - intro	
	    putimage(0, 0, end_bg, COPY_PUT);
    	
    /*
		// sair 
 	    if (btn_sair_hover_bool)
 		   	putimage(btn_sair_X, btn_sair_Y, btn_sair_hover, COPY_PUT); 
 	    else
    		putimage(btn_sair_X, btn_sair_Y, btn_sair, COPY_PUT);
	*/
		setvisualpage(pg);
	/*
		// mouse hovering
			if (GetCursorPos(&P)) 
	     	 	if (ScreenToClient(janela, &P)){		
	        
		// sair
			btn_sair_hover_bool = false; 
	        if (btn_sair_X <= P.x && P.x <= btn_sair_X+btnX_glb-1 && btn_sair_Y <= P.y && P.y <= btn_sair_Y+btnY_glb-1)
	          	btn_sair_hover_bool = true;
	
			if(GetKeyState(VK_LBUTTON)&0x80){
	            // sair botao
			 	if (btn_sair_X <= P.x && P.x <= btn_sair_X+btnX_glb-1 && btn_sair_Y <= P.y && P.y <= btn_sair_Y+btnY_glb-1){
			 		Fim = true;
			 		
				}
			}
		}*/
	}
}	


// --------------------------------------------> game over <--------------------------------------------

void Game_Over(){
	bool Fim = false;
  	int pg = 1;
  	POINT P;
  	HWND janela;
	
//	mciSendString("open .\\sons\\laught_death_2.mp3 type MPEGVideo alias repetido", NULL, 0, 0);
//	mciSendString("play repetido repeat", NULL, 0, 0);

	//sndPlaySound(NULL, NULL);
//	mciSendString("stop repetido", NULL, 0, 0);    // pára a reprodução do alias repetido

// Som Game over

 	mciSendString("open .\\sons\\game_over.mp3 type MPEGVideo alias game_over", NULL, 0, 0);
 	mciSendString("play game_over", NULL, 0, 0); 
 	
	//sndPlaySound(".\\sons\\game_over.wav", SND_ASYNC);

  	// botoes posicao
  	btn_retry_X = 530;
  	btn_retry_Y = 550;
  	
  	/*
 	btn_menu_X = 530;
	btn_menu_Y = 450;
	
	btn_sair_go_X = 530;
	btn_sair_go_Y = 550;
	*/
	
	menu_return = 0;

	// botoes selecionados
	bool btn_retry_hover_bool = false;
  	bool btn_sair_go_hover_bool = false;
	bool btn_menu_hover_bool = false;

  	
// -------------------------------------------- imagens ------------------------------------------------------
	
	// background imagem
  	tam = imagesize(0, 0, telaX_glb-1, telaY_glb-1);
  	menu_bg = malloc(tam);
  	readimagefile("image/menu/game_over.bmp", 0, 0, telaX_glb-1, telaY_glb-1);
  	getimage(0, 0, telaX_glb-1, telaY_glb-1, menu_bg);
  	
	// botoes
  	cleardevice();
  	
  	// retry 
  	tam = imagesize(0, 0, btnX_glb-1, btnY_glb-1);
  	btn_retry = malloc(tam);
  	readimagefile("image/menu/retry.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_retry);
  	
  	btn_retry_hover = malloc(tam);
  	readimagefile("image/menu/retry_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_retry_hover);

	/* BROKEN

	// menu
  	btn_menu = malloc(tam);
  	readimagefile("image/menu/menu.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_menu);
  	
	btn_menu_hover = malloc(tam);
  	readimagefile("image/menu/menu_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_menu_hover);	
  	
	// sair
	btn_sair_go = malloc(tam);
  	readimagefile("image/menu/sair_go.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair_go);	
  	
  	btn_sair_go_hover = malloc(tam);
  	readimagefile("image/menu/sair_go_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_sair_go_hover);	
	
	*/
		
	janela = GetForegroundWindow(); 
	
	while (!Fim) {
		if (pg == 1) pg = 2; else pg = 1;
    	setactivepage(pg);
    	putimage(0, 0, menu_bg, COPY_PUT);
    	
    // botao sprite
    
    	// retry 
     	if (btn_retry_hover_bool)
      		putimage(btn_retry_X, btn_retry_Y, btn_retry_hover, COPY_PUT); 
    	else
     		putimage(btn_retry_X, btn_retry_Y, btn_retry, COPY_PUT);
    
    /*
    	// Menu 
        if (btn_menu_hover_bool)
      		putimage(btn_menu_X, btn_menu_Y, btn_menu_hover, COPY_PUT); 
    	else
     		putimage(btn_menu_X, btn_menu_Y, btn_menu, COPY_PUT);

     	// sair 
     	if (btn_sair_go_hover_bool)
      		putimage(btn_sair_go_X, btn_sair_go_Y, btn_sair_go_hover, COPY_PUT); 
    	else
     		putimage(btn_sair_go_X, btn_sair_go_Y, btn_sair_go, COPY_PUT);
    */ 	
		setvisualpage(pg);

	// mouse hovering	
		if (GetCursorPos(&P)) 
     	 	if (ScreenToClient(janela, &P)) {		
     	 	
     	// retry
        btn_retry_hover_bool = false; 
        if (btn_retry_X <= P.x && P.x <= btn_retry_X+btnX_glb-1 && btn_retry_Y <= P.y && P.y <= btn_retry_Y+btnY_glb-1)
          btn_retry_hover_bool = true;	
    /* 	 	
		// menu
        btn_menu_hover_bool = false; 
        if (btn_menu_X <= P.x && P.x <= btn_menu_X+btnX_glb-1 && btn_menu_Y <= P.y && P.y <= btn_menu_Y+btnY_glb-1)
          btn_menu_hover_bool = true;

		// sair
		btn_sair_go_hover_bool = false; 
     	if (btn_sair_go_X <= P.x && P.x <= btn_sair_go_X+btnX_glb-1 && btn_sair_go_Y <= P.y && P.y <= btn_sair_go_Y+btnY_glb-1)
        btn_sair_go_hover_bool = true;
	*/	
		if(GetKeyState(VK_LBUTTON)&0x80) {
			
			// retry botao
        	if (btn_retry_X <= P.x && P.x <= btn_retry_X+btnX_glb-1 && btn_retry_Y <= P.y && P.y <= btn_retry_Y+btnY_glb-1){
           		Game();
			}
	/*
          	// menu botao
        	if (btn_menu_X <= P.x && P.x <= btn_menu_X+btnX_glb-1 && btn_menu_Y <= P.y && P.y <= btn_menu_Y+btnY_glb-1){
        		mciSendString("close game_over", NULL, 0, 0);
            	menu_return = 1;
            	Menu();
            	
			}	
			// sair botao
		 	else if (btn_sair_go_X <= P.x && P.x <= btn_sair_go_X+btnX_glb-1 && btn_sair_go_Y <= P.y && P.y <= btn_sair_go_Y+btnY_glb-1){
            	mciSendString("close game_over", NULL, 0, 0);
				Fim = true;
			}
      	*/
		}
		

		}
	}
	}

	
// -------------------------------------------> creditos <-------------------------------------------------	
	
void Creditos(){	
//-------------------------------------------- variaveis ----------------------------------------------------   
	bool Fim = false;
  	int pg = 1;
  	POINT P;
  	HWND janela;
	
	btn_voltar_X = 540;
	btn_voltar_Y = 630;
	menu_return = 0;
	
	// botoes selecionados
  	bool btn_voltar_hover_bool = false;

// -------------------------------------------- imagens ------------------------------------------------------
	
// background imagem
  	tam = imagesize(0, 0, telaX_glb-1, telaY_glb-1);
  	menu_bg = malloc(tam);
  	readimagefile("image/menu/creditos2.bmp", 0, 0, telaX_glb-1, telaY_glb-1);
  	getimage(0, 0, telaX_glb-1, telaY_glb-1, menu_bg);
  	
// botoes
  	cleardevice();

	// voltar ao menu
	tam = imagesize(0, 0, btnX_glb-1, btnY_glb-1);
	btn_voltar = malloc(tam);
  	readimagefile("image/menu/voltar.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_voltar);	
  	
  	btn_voltar_hover = malloc(tam);
  	readimagefile("image/menu/voltar_hover.bmp", 0, 0, btnX_glb-1, btnY_glb-1);
  	getimage(0, 0, btnX_glb-1, btnY_glb-1, btn_voltar_hover);	

			
	janela = GetForegroundWindow(); 
	
	while (!Fim) {
		if (pg == 1) pg = 2; else pg = 1;
    	setactivepage(pg);
    	putimage(0, 0, menu_bg, COPY_PUT);
    	
    // botao sprite

     	// voltar 
     	if (btn_voltar_hover_bool)
      		putimage(btn_voltar_X, btn_voltar_Y, btn_voltar_hover, COPY_PUT); 
    	else
     		putimage(btn_voltar_X, btn_voltar_Y, btn_voltar, COPY_PUT);
     	
		setvisualpage(pg);
		
	// mouse hovering	
		if (GetCursorPos(&P)){
     	 	if (ScreenToClient(janela, &P)){
	// voltar
		btn_voltar_hover_bool = false; 
        if (btn_voltar_X <= P.x && P.x <= btn_voltar_X+btnX_glb-1 && btn_voltar_Y <= P.y && P.y <= btn_voltar_Y+btnY_glb-1)
          btn_voltar_hover_bool = true;
		
		if(GetKeyState(VK_LBUTTON)&0x80){
           	// voltar botao
		 	if (btn_voltar_X <= P.x && P.x <= btn_voltar_X+btnX_glb-1 && btn_voltar_Y <= P.y && P.y <= btn_voltar_Y+btnY_glb-1){
				Menu();
				menu_return = 1;	
			 }
		} 
		if(menu_return == 1){
			if(GetKeyState(VK_LBUTTON)&0x80){
           	// sair botao
		 	if (btn_sair_X <= P.x && P.x <= btn_sair_X+btnX_glb-1 && btn_sair_Y <= P.y && P.y <= btn_sair_Y+btnY_glb-1)
				Fim = true;
			} 
		}
			}
		}
	}
}


// ------------------------------------------  ---> game <---------------------------------------------------

void Game(){
// --------------------------------------------> variaveis <-------------------------------------------
		
	// tam	
	int i, j, TamB, TamF, TamSp, TamHp, TamFr, TamDash, TamBG, TamTS;
	
	// resoluçao tela
	telaX = 1280, telaY = 720; 
	zeroX = 0, zeroY = 0;
	
	int pg = 2;
	char tecla = 0;
	int cont, tam = 1;

	Tmain *main;

	main = (Tmain *)malloc(sizeof(Tmain) * tam);


	// BGM - fase 1	

	//sndPlaySound(NULL, NULL);
	mciSendString("stop intro", NULL, 0, 0); // pára a reprodução do alias repetido
//	sndPlaySound(".\\sons\\sound_scene2.wav", SND_ASYNC + SND_LOOP);
	

	// som
	
	// game over
	mciSendString("stop laugh_death1", NULL, 0, 0); 
    mciSendString("stop game_over", NULL, 0, 0); 

// -----------------------------------------> sprite tam <--------------------------------------------------
	
	// player sprite img
	player_x = 64;
	player_y = 64;
	player_passoX = 4;
	player_passoY = 0;;
	
	// boss sprite img
	boss_x = 64;
	boss_y = 64;
	boss_passoX = 3;
	
	// floor sprite img
	floor_x = 16;
	floor_y = 16;
	floor_passoX = 0;
	floor_passoY = 0;
	floor_vx = 0;
	floor_vy = 0;
	fmov_x = 0;
	fmov_y = 0;
	floor_effect = 0;
	
	// spell sprite img
	spell_x = 32;
	spell_y = 32;
	spell_passoX = 2;
	spell_passoY = 2;
	Sp_cont = 0;
	
	// spell 2
	spell_2_passoX = 6;
	spell_2_passoY = 8;
	Sp_2x_min = (telaX/2)-280;
	Sp_2x_max = (telaX/2)+215;
	Sp_2y_min = (telaY/2)-50;
	Sp_2y_max = (telaX/2)-15;

	// background img - fase 1
	bg_1x = 1280;
	bg_1y = 720;
	
	// frag sprite img
	frag_x = 32;
	frag_y = 32;
	frag_passoX = 0;
	frag_passoY = 0;
	
	// hp sprite img
	hp_x = 32;
	hp_y = 32;
	hp_qtd = 1;
	hp_col = 0;
	
	// pulo
	pulo = 5;
	tam_pulo = 195;
	teto_b = 0;
	caindo = 0;
	pres_esp = 0;
	
	// dash sprite
	dash_x = 32;
	dash_y = 32;
	
	// dash / mov speed
	pres_shift = 0;
	dash_qtd = 2;
	dash_cd = 0;
	cd_timer = 0;
	
	// time stop 
	time_stop_x = 64;
	time_stop_y = 64;
	time_stop_qtd = 1;

// ---------------------------------------------> tela grafica <------------------------------------------------------
	
	setbkcolor(RGB(0, 20, 50));
	
// --------------------------------------------> background fase 1 <-----------------------------------------
	
	// bg img
	TamBG = imagesize(0, 0, telaX-1, telaY-1);
	BG = malloc(TamBG);

	// bg sprite 
	readimagefile("image/main/bg_1.bmp", 0, 0, bg_1x-1, bg_1y-1);
	getimage(0, 0, bg_1x-1, bg_1y-1, BG);
	 
// --------------------------------------------> player <------------------------------------------------

		
	// player - img 
	for (i = 0; i < tam; i++){
		main[i].tam_main = imagesize(0, 0, player_x-1, player_y-1);
		S = malloc(main[i].tam_main);
		SM = malloc(main[i].tam_main);
	}
	// player - sprite
	readimagefile("image/main/player_sprite.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, S);
	
	// player - mask  
	readimagefile("image/main/player_mask.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, SM);
	
	// player - spawn
	px = zeroX+player_x;
	py = telaY-player_y-floor_x-5;
	
// -----------------------------------------------> boss <----------------------------------------------
	
	// boss - img
	TamB = imagesize(0, 0, boss_x-1, boss_y-1);
	B = malloc(TamB);
	BM = malloc(TamB);
	
	// boss - sprite
	readimagefile("image/boss/boss_sprite.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, B);
	
	// boss - mask
	readimagefile("image/boss/boss_mask.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, BM);
	
	// boss - spawn
	bx = 20;
	by = 10;
	
// -----------------------------------------> floor/plataforma <-----------------------------------------

	// flor - img
	TamF = imagesize(0, 0, floor_x-1, floor_y-1);
	F = malloc(TamF);

	// flor - sprite
	readimagefile("image/elements/floor_sprite.bmp", 0, 0, floor_x-1, floor_y-1);
	getimage(0, 0, floor_x-1, floor_y-1, F);
	
	// flor - spawn
	fx = zeroX+1;
	fy = telaY-floor_y-5;
	
	
// ------------------------------------------------> pulo/teto <-----------------------------------------	

	teto_h = (fy-floor_vy)-(tam_pulo);
	teto_l = (fy-floor_vy)-player_y-pulo;
	
// ----------------------------------------------> spell <---------------------------------------------------

	// spell - img  
	TamSp = imagesize(0, 0, spell_x-1, spell_y-1);
	Sp = malloc(TamSp);
	SpM = malloc(TamSp);
	
	// spell - sprite
	readimagefile("image/boss_magic/spell_sprite.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, Sp);
	
	// spell - mask
	readimagefile("image/boss_magic/spell_mask.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, SpM);
	
	// spell - spawn
	Spx = 20+spell_x;
	Spy = 10+spell_y;
	
	Sp_2x = (telaX/2)-280+100;
	Sp_2y = (telaX/2)-280+100;
	
// --------------------------------------------> fragmento <----------------------------------------------
	
	// frag - img
	TamFr = imagesize(0, 0, frag_x-1, frag_y-1);
	Fr = malloc(TamFr);
	FrM = malloc(TamFr);	
		
	// frag - sprite
	readimagefile("image/elements/frag_sprite.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, spell_y-1, Fr);
	
	// frag - mask
	readimagefile("image/elements/frag_mask.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, frag_y-1, FrM);
	
	// frag - spawn
	fr_x = 20;
	fr_y = 10;
	frag_qtd = 1;
	frag_qtd_obt = 0;
	
// -------------------------------------------> time stop <----------------------------------------------

	// time stop - img
	TamTS = imagesize(0, 0, time_stop_x-1, time_stop_y-1);
	TS = malloc(TamTS);
	TSM = malloc(TamTS);	
		
	// time stop - sprite
	readimagefile("image/elements/time_stop_sprite.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TS);
	
	// time stop - mask
	readimagefile("image/elements/time_stop_mask.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TSM);

	// time stop - spawn
	TS_x = 600;
	TS_y = 480;
	
// -------------------------------------------------> HP <---------------------------------------------------

	// HP - img
	TamHp = imagesize(0, 0, hp_x-1, hp_y-1);
	HpS = malloc(TamHp);
	HpM = malloc(TamHp);
	
	// HP - sprite
	readimagefile("image/hud/hp_sprite.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpS);
	
	// HP - mask
	readimagefile("image/hud/hp_mask.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpM);
	
	// HP - spawn
	hpx = 0;
	hpy = telaY-hp_y-20;;
	
// ----------------------------------------------> dash <-------------------------------------
	/*
	// dash - img
	TamDash = imagesize(0, 0, dash_x-1, dash_y-1);
	D2S = malloc(TamDash);
	D2M = malloc(TamDash);
	D1S = malloc(TamDash);
	D1M = malloc(TamDash);
	D0S = malloc(TamDash);
	D0M = malloc(TamDash);
	
	// dash 2 - sprite
	readimagefile("image/hud/dash_2.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D2S);
	
	// dash 2 - mask
	readimagefile("image/hud/dash_2.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D2M);
	
	// dash 1 - sprite
	readimagefile("image/hud/dash_1.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D1S);
	
	// dash 1 - mask
	readimagefile("image/hud/dash_1.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D1M);		
	
	// dash 0 - sprite
	readimagefile("image/hud/dash_0.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D0S);
	
	// dash 0 - mask
	readimagefile("image/hud/dash_0.bmp", 0, 0, dash_x-1, dash_y-1);
	getimage(0, 0, dash_x-1, dash_y-1, D0M);
	
	dashX = 120;
	dashY = 10;
	*/
	
// -------------------------------------------> loop principal <---------------------------------------------

	while(tecla != 27){
		gt2 = GetTickCount();
		if (gt2-gt1 > 1000/70){ 
		gt1 = gt2;
    	if (pg == 1) pg = 2; else pg=1;
    
		setactivepage(pg);
    	cleardevice();
		
// background - fase 1
    	putimage(telainX, telainY, BG, COPY_PUT);	
	
// ----------------------------------------------> player <------------------------------------------------	
{
// player sprite
		putimage(px, py, SM, AND_PUT);
		putimage(px, py, S, OR_PUT);
			
		// player img - comandos teclado
		
		// direita (d)
		if(GetKeyState(68)&0x80) 
		  px += player_passoX;
		// esquerda (a)
		if(GetKeyState(65)&0x80) 
		  px -= player_passoX;
		// cima (w)
//	    if(GetKeyState(87)&0x80)  
//	      py -= player_passoY;
	    // baixo (s)
//	    if(GetKeyState(83)&0x80) 
//	      py += player_passoY;
	
		// atravessa tela em X
		if (px+32 > telaX) 
	      px = (telaX*0)-player_x;
	    if (px+32 < telaX*0-player_x)
	    	px = telaX-32;
}		

// -------------------------------------------------> boss <-------------------------------------------------
{
// boss sprite
		putimage(bx, by, BM, AND_PUT);
		putimage(bx, by, B, OR_PUT);
		
		// boss movimento alternado - colide X
		for(i = 0; i < 1; i++){
			bx += boss_passoX;
			if (bx <= zeroX || bx >= telaX-boss_x)
			boss_passoX = -boss_passoX;
		}
		
		// colisao boss <-> player	
		if((px <= bx && bx <= px+player_x) && (py <= by && by <= py+player_y) ||
		   (px <= bx+boss_x && bx <= px+player_x) && (py <= by+boss_y && by <= py+player_y)) {
			hp_col = 1;
		}
				
/*   	// boss movimento continuo - atravessa X
     	if (bx > zeroX-boss_x){
     		bx += boss_passoX;
    		if (bx == telaX-boss_x)
     		bx = boss_x-boss_x;
		} 
*/
}	
	
// --------------------------------------------------> plataformas <------------------------------------------

// plataforma inferior - base
{
/*
    	for(i = 0; i <= telaX; i+=16){
    		floor_vx = 0;
    		putimage(fx+i, fy, F, COPY_PUT);
    		
		//if (py+player_y >= (fy-floor_vy) ){
		// colisao
		if ((px <= (fx+i+floor_vx) && (fx+i+floor_vx)<= px+player_x) && py+player_y == (fy-floor_vy)){			
			player_passoY = 0;
		
		// pulo
			if(GetKeyState(32)&0x80){
				teto_h = fy-floor_vy-tam_pulo;
				py -= pulo;	
			}
		
 		}	
		}*/

	// base		
		for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 0;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}	
		
		}
		}
}

// plataformas esquerda
{
	// 1
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 10;
			floor_vy = 100;
			putimage(fx+i+floor_vx, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}

	// 2	
		for(i = telainX; i < telaX/8; i+=16){
			floor_vx = 10;
			floor_vy = 200;
			fmov_x = 100;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
		
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}				
		}
		
	// 3	
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 10;
			floor_vy = 275;
			fmov_x = 20;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
	
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}				
		}
		
	// 4	
		for(i = telainX; i < telaX/36; i+=16){
			floor_vx = 10;
			floor_vy = 380;
			fmov_x = 5;
			putimage(fx+i+floor_vx, fy-floor_vy, F, COPY_PUT);
	
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}			
		}		
		
	// 5
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 10;
			floor_vy = 420;
			fmov_x = 220;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
	
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
	
		}			
		}	
		
	// 6 - trap
	if (floor_effect == 0){
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 10;
			floor_vy = 540;
			fmov_x = 120;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
	
		// colisao
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			floor_effect = 1;
		}
		}			
	} 
}
		
// plataformas centro
{
	// 1
		for(i = telaX/6; i < telaX/4; i+=16){
			floor_vx = 200;
			floor_vy = 75;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao plataforma
		//if ((px+player_x >= fx+floor_vx+i+fmov_x && px+player_x <= fx+i+floor_vx+fmov_x+player_x) &&
		 //	 py+player_y == (fy-floor_vy)){
		//	if ((px <= (fx+i+floor_vx) && (fx+i+floor_vx)<= px+player_x) && py+player_y == (fy-floor_vy)){
		//	caindo = 0;
		//	py = (fy-floor_vy-player_y+pulo);
			
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 2
		for(i = telaX/6; i < telaX/4; i+=16){
			floor_vx = 200;
			floor_vy = 75;
			fmov_x = 300;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 3
		for(i = telainX; i < telaX/18; i+=16){
			floor_vx = telaX/6+200;
			floor_vy = 175;
			fmov_x = -50;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
			
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 4
		for(i = telainX; i < telaX/16; i+=16){
			floor_vx = telaX/6+200;
			floor_vy = 175;
			fmov_x = 360;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
				
	// 5
		for(i = telainX; i < telaX/42; i+=16){
			floor_vx = telaX/6+200;
			floor_vy = 300;
			fmov_x = 30;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
				
	// 6
		for(i = telainX; i < telaX/42; i+=16){
			floor_vx = telaX/6+200;
			floor_vy = 300;
			fmov_x = 380;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 7
		for(i = telainX; i < telaX/42; i+=16){
			floor_vx = telaX/6+200;
			floor_vy = 400;
			fmov_x = 180;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
}
			
// plataformas direita
{
	// 1
		for(i = telainX; i < telaX/16; i+=16){
			floor_vx = 1150;
			floor_vy = 240;
			fmov_x = 10;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 2
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 1050;
			floor_vy = 350;
			fmov_x = 10;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
		
	// 3
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 1120;
			floor_vy = 480;
			fmov_x = 10;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}
			
	// 4
		for(i = telainX; i < telaX/60; i+=16){
			floor_vx = 900;
			floor_vy = 490;
			fmov_x = 10;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}
		}			
	
}
		
// plataforma superior
{
		for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 620;
    		putimage(fx+i+floor_vx, fy-floor_vy, F, COPY_PUT);
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}		
		}
		
}

// ----------------------------------------------------------> pulo <-----------------------------------------------
{

		// tecla espaco
		if(GetKeyState(32)&0x80)
			pres_esp = 1;
		
		// pulo	
		if (pres_esp == 1 || (py <= teto_h && caindo != 1))
	        py -= pulo;
	    // teto superior
		if (py <= teto_h)
	        caindo = 1;
		// pulo volta	
		if (caindo == 1)
		  	py += pulo+5;
		// teto inferior	
		if (py > teto_l){
		  	caindo = 0;
		  	pres_esp = 0;
		}	
		
}	
	
// ------------------------------------------------------> mov speed / dash <--------------------------------------
{
	
	// tecla shift
	if(GetKeyState(16)&0x80)
		pres_shift = 1;
	

	// direita
	if ((pres_shift == 1) && (GetKeyState(68)&0x80)) {
		player_passoX = 6;
	    px += player_passoX;
	    
		if (px >= (player_passoX*6)+player_x){
	    pres_shift = 0;
	    player_passoX = 4;
		} 
	}
	// esquerda    
	if ((pres_shift == 1) && (GetKeyState(65)&0x80)){
		player_passoX = 6;
		px -= player_passoX;
	
		if (px >= -player_passoX*6){
		pres_shift = 0;
		player_passoX = 4;   
		} 
	}
	
	/*	
	if ( ((pres_shift == 1) && (GetKeyState(68)&0x80)) || ((pres_shift == 1) && (GetKeyState(65)&0x80)) ) {
		dash_qtd -= 1;
	}	
		
	
	// cooldown
		if (dash_qtd < 2){
		 dash_cd = 1;
		}
		if (dash_cd == 1){
		cd_timer += 30; 
		}
		if (cd_timer == 120){
		dash_qtd += 1;
		} 
		
	// no dash	
		if ((dash_qtd == 0) && (GetKeyState(16)&0x80) ){
			pres_shift = 3;
			player_passoX = 4;
		}	
		
	// dash sprite		
		if (dash_qtd == 2){
		putimage(dashX, dashY, D2M, AND_PUT);
		putimage(dashX, dashY, D2S, OR_PUT);
		}
		if (dash_qtd == 1){
		putimage(dashX, dashY, D1M, AND_PUT);
		putimage(dashX, dashY, D1S, OR_PUT);
		}
		if (dash_qtd == 0){
		putimage(dashX, dashY, D0M, AND_PUT);
		putimage(dashX, dashY, D0S, OR_PUT);
		}
	*/
}
	
// --------------------------------------------------------> spell <-----------------------------------------------------
{
	
// spell sprite - main
	
		// posicao inicial
		for(i = 0; i < tam; i++){
			putimage(Spx, Spy, SpM, AND_PUT);
			putimage(Spx, Spy, Sp, OR_PUT);
		}
		
		// spell movimento
		for(i = 0; i < 5; i++){
		
			
			// spell X
			Spx += spell_passoX;
			if (Spx <= zeroX || Spx >= telaX-spell_x){
			spell_passoX = -spell_passoX;
		
			}
			
		
			// spell Y
			Spy += spell_passoY;
			if (Spy <= zeroY || Spy >= telaY-spell_y){
			spell_passoY= -spell_passoY;
			
			}
			
		}
			
		
		// colisao spell <-> player	
		if((px <= Spx && Spx <= px+player_x) && (py <= Spy && Spy <= py+player_y) ||
		   (px <= Spx+spell_x && Spx <= px+player_x) && (py <= Spy+spell_y && Spy <= py+player_y)) {
			hp_col = 1;
		}
		
// spell - centro

	for(i = 0; i < tam; i++){
		putimage(Sp_2x, Sp_2y, SpM, AND_PUT);
		putimage(Sp_2x, Sp_2y, Sp, OR_PUT);		
		
	}
	// spell mov X
		for(i = 0; i < 1; i+=5){
			
			Sp_2x += spell_2_passoX;
			if (Sp_2x <= Sp_2x_min || Sp_2x >= Sp_2x_max-spell_x){
			spell_2_passoX = -spell_2_passoX;
			}
			
	// spell mov Y
			Sp_2y += spell_2_passoY;
			if (Sp_2y <= Sp_2y_min || Sp_2y >= Sp_2y_max-spell_y){
			spell_2_passoY= -spell_2_passoY;
			}
			}
	
	// colisao spell 2 <-> player	
		if((px <= Sp_2x && Sp_2x <= px+player_x) && (py <= Sp_2y && Sp_2y <= py+player_y) ||
		   (px <= Sp_2x+spell_x && Sp_2x <= px+player_x) && (py <= Sp_2y+spell_y && Sp_2y <= py+player_y)) {
			hp_col = 1;
		}
	
	
	// hitbox spell 2 	
	//rectangle((telaX/2)-280, (telaX/2)-15, telaX/2+215, telaY/2-50);

}

// --------------------------------------------------------> HP <----------------------------------------------
{
		
// player hp
		if(hp_col == 1){
			hp_qtd = 0;
			hp_col = 0;
		}
		
// HP sprite
	/*	// 3
		if (hp_qtd == 3){
		for(i = 0; i < 61; i+=30){
		putimage(hpx+i, hpy, HpM, AND_PUT);
		putimage(hpx+i, hpy, HpS, OR_PUT);
		}
		}
		// 2
		if (hp_qtd == 2){
		for(i = 0; i < 31; i+=30){
		putimage(hpx+i, hpy, HpM, AND_PUT);
		putimage(hpx+i, hpy, HpS, OR_PUT);
		}
		}*/
		// 1
		if (hp_qtd == 1){
		for(i = 0; i < tam; i++){
		putimage(hpx, hpy, HpM, AND_PUT);
		putimage(hpx, hpy, HpS, OR_PUT);
		}
		}
}

// -------------------------------------------------> frag <----------------------------------------------
{
// fragmento sprite
		if (frag_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(fr_x, fr_y, FrM, AND_PUT);
		putimage(fr_x, fr_y, Fr, OR_PUT);
		}
		}
		
}

// ----------------------------------------------------------> time stop <-------------------------------------------
{
	
// time stop sprite	
		if (time_stop_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(TS_x, TS_y, TSM, AND_PUT);
		putimage(TS_x, TS_y, TS, OR_PUT);
		}
		}

// colisao player <-> time stop (retangulo <-> retangulo)
		if((px <= TS_x && TS_x <= px+player_x) && (py <= TS_y && TS_y <= py+player_y) ||
		   (px <= TS_x+time_stop_x && TS_x <= px+player_x) && (py <= TS_y+time_stop_y && TS_y <= py+player_y)){
			spell_passoX = 0;
			spell_passoY = 0;
			time_stop_qtd = 0;
		}		
	
}

// --------------------------------------------------> fase 2 (obter fragmento) <----------------------------------------------
{
	// colisao player <-> fragmento (retangulo <-> retangulo)
		if((px <= fr_x && fr_x <= px+player_x) && (py <= fr_y && fr_y <= py+player_y) || (px <= fr_x+frag_x && fr_x <= px+player_x) && (py <= fr_y+frag_y && fr_y <= py+player_y)) {
			frag_qtd_obt = 1;
			Fase_2();
		}		
}

// ---------------------------------------------------> game over <-------------------------------------
{		
		if (hp_qtd == 0){
	//		mciSendString("open .\\sons\\laugh_death2.mp3 type MPEGVideo alias repetido", NULL, 0, 0);
	//		sndPlaySound(".\\sons\\hit_skill.wav", SND_ASYNC);
	//		delay (250);
	//		sndPlaySound(".\\sons\\laugh_death1.wav", SND_SYNC);
			Game_Over();
		}
		
}		
		setvisualpage(pg);

	//	delay(1);
	}
	fflush(stdin);  
	
	
// comando teclas
 		if (kbhit()){
     		tecla = getch();
   		
   			//ESC
			if(tecla == 27)
		 		exit(0);
		}
	}

// fecha tela grafica
	closegraph();	
}

void Fase_2(){
// --------------------------------------------------> variaveis <-------------------------------------------
		
	// tam	
	int i, j, TamB, TamF, TamSp, TamHp, TamFr, TamDash, TamBG, TamTS;
	
	// resoluçao tela
	telaX = 1280, telaY = 720; 
	zeroX = 0, zeroY = 0;
	
	int pg = 2;
	char tecla = 0;
	int cont, tam = 1;
	
	Tmain *main;
	main = (Tmain *)malloc(sizeof(Tmain) * tam);

	// BGM - fase 1	

	//sndPlaySound(NULL, NULL);
	mciSendString("stop intro", NULL, 0, 0); // pára a reprodução do alias repetido
//	sndPlaySound(".\\sons\\sound_scene2.wav", SND_ASYNC + SND_LOOP);
	


// -----------------------------------------> sprite tam <--------------------------------------------------
	
	// player sprite img
	player_x = 64;
	player_y = 64;
	player_passoX = 4;
	player_passoY = 0;
	
	// boss sprite img
	boss_x = 64;
	boss_y = 64;
	bx_min = 420;
	bx_max = 850;
	by_min = 0;
	by_max = 0;
	boss_passoX = 6;
	
	// floor sprite img
	floor_x = 16;
	floor_y = 16;
	floor_passoX = 0;
	floor_passoY = 0;
	floor_vx = 0;
	floor_vy = 0;
	fmov_x = 0;
	fmov_y = 0;
	
	// spell sprite img
	spell_x = 32;
	spell_y = 32;
	spell_passoX = 8;
	spell_passoY = 0;
	Sp_cont = 0;
	
	// spell 2
	spell_2_passoX = 4;
	spell_2_passoY = 4;
	Sp_2x_min = (telaX/2)-280;
	Sp_2x_max = (telaX/2)+215;
	Sp_2y_min = (telaY/2)-50;
	Sp_2y_max = (telaX/2)-15;

	// background img - fase 1
	bg_1x = 1280;
	bg_1y = 720;
	
	// frag sprite img
	frag_x = 32;
	frag_y = 32;
	frag_passoX = 0;
	frag_passoY = 0;
	
	// hp sprite img
	hp_x = 32;
	hp_y = 32;
	hp_qtd = 1;
	hp_col = 0;
	
	// pulo
	pulo = 5;
	tam_pulo = 195;
	teto_b = 0;
	caindo = 0;
	pres_esp = 0;
	
	// dash sprite
	dash_x = 32;
	dash_y = 32;
	
	// dash / mov speed
	pres_shift = 0;
	dash_qtd = 2;
	dash_cd = 0;
	cd_timer = 0;
	
	// time stop 
	time_stop_x = 64;
	time_stop_y = 64;
	time_stop_qtd = 1;

// ---------------------------------------------> tela grafica <------------------------------------------------------
	
	setbkcolor(RGB(0, 20, 50));
	
// --------------------------------------------> background fase 1 <-----------------------------------------
	
	// bg img
	TamBG = imagesize(0, 0, telaX-1, telaY-1);
	BG = malloc(TamBG);

	// bg sprite 
	readimagefile("image/main/bg_1.bmp", 0, 0, bg_1x-1, bg_1y-1);
	getimage(0, 0, bg_1x-1, bg_1y-1, BG);
	 
// --------------------------------------------> player <------------------------------------------------

		
	// player - img 
	for (i = 0; i < tam; i++){
		main[i].tam_main = imagesize(0, 0, player_x-1, player_y-1);
		S = malloc(main[i].tam_main);
		SM = malloc(main[i].tam_main);
	}
	// player - sprite
	readimagefile("image/main/player_sprite.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, S);
	
	// player - mask  
	readimagefile("image/main/player_mask.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, SM);
	
	// player - spawn
	px = telainX;
	py = telainY;
	
// -----------------------------------------------> boss <----------------------------------------------
	
	// boss - img
	TamB = imagesize(0, 0, boss_x-1, boss_y-1);
	B = malloc(TamB);
	BM = malloc(TamB);
	
	// boss - sprite
	readimagefile("image/boss/boss_sprite.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, B);
	
	// boss - mask
	readimagefile("image/boss/boss_mask.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, BM);
	
	// boss - spawn
	bx = telaX/2;
	by = 350;
	
// -----------------------------------------> floor/plataforma <-----------------------------------------

	// flor - img
	TamF = imagesize(0, 0, floor_x-1, floor_y-1);
	F = malloc(TamF);

	// flor - sprite
	readimagefile("image/elements/floor_sprite.bmp", 0, 0, floor_x-1, floor_y-1);
	getimage(0, 0, floor_x-1, floor_y-1, F);
	
	// flor - spawn
	fx = zeroX+1;
	fy = telaY-floor_y-5;
	
	
// ------------------------------------------------> pulo/teto <-----------------------------------------	

	teto_h = (fy-floor_vy)-(tam_pulo);
	teto_l = (fy-floor_vy)-player_y-pulo;
	
// ----------------------------------------------> spell <---------------------------------------------------

	// spell - img  
	TamSp = imagesize(0, 0, spell_x-1, spell_y-1);
	Sp = malloc(TamSp);
	SpM = malloc(TamSp);
	
	// spell - sprite
	readimagefile("image/boss_magic/spell_sprite.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, Sp);
	
	// spell - mask
	readimagefile("image/boss_magic/spell_mask.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, SpM);
	
	// spell - spawn
	Spx = 10+spell_x;
	Spy = 700-spell_y;
	
	Sp_2x = (telaX/2)-280+100;
	Sp_2y = (telaX/2)-280+100;
	
// --------------------------------------------> fragmento <----------------------------------------------
	
	// frag - img
	TamFr = imagesize(0, 0, frag_x-1, frag_y-1);
	Fr = malloc(TamFr);
	FrM = malloc(TamFr);	
		
	// frag - sprite
	readimagefile("image/elements/frag_sprite.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, spell_y-1, Fr);
	
	// frag - mask
	readimagefile("image/elements/frag_mask.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, frag_y-1, FrM);
	
	// frag - spawn
	fr_x = 780;
	fr_y = telaY-frag_y-20;
	frag_qtd = 1;
	frag_qtd_obt = 1;
	
// -------------------------------------------> time stop <----------------------------------------------

	// time stop - img
	TamTS = imagesize(0, 0, time_stop_x-1, time_stop_y-1);
	TS = malloc(TamTS);
	TSM = malloc(TamTS);	
		
	// time stop - sprite
	readimagefile("image/elements/time_stop_sprite.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TS);
	
	// time stop - mask
	readimagefile("image/elements/time_stop_mask.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TSM);

	// time stop - spawn
	TS_x = 610;
	TS_y = 345;
	
// -------------------------------------------------> HP <---------------------------------------------------

	// HP - img
	TamHp = imagesize(0, 0, hp_x-1, hp_y-1);
	HpS = malloc(TamHp);
	HpM = malloc(TamHp);
	
	// HP - sprite
	readimagefile("image/hud/hp_sprite.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpS);
	
	// HP - mask
	readimagefile("image/hud/hp_mask.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpM);
	
	// HP - spawn
	hpx = 0;
	hpy = telaY-hp_y-20;
	
// -------------------------------------------> loop principal <---------------------------------------------

	while(tecla != 27){
		gt2 = GetTickCount();
		if (gt2-gt1 > 1000/70){ 
		gt1 = gt2;
    	if (pg == 1) pg = 2; else pg=1;
    
		setactivepage(pg);
    	cleardevice();
		
// background - fase 1
    	putimage(telainX, telainY, BG, COPY_PUT);
	
// ----------------------------------------------> player <------------------------------------------------	
{
// player sprite
		putimage(px, py, SM, AND_PUT);
		putimage(px, py, S, OR_PUT);
			
		// player img - comandos teclado
		
		// direita (d)
		if(GetKeyState(68)&0x80) 
		  px += player_passoX;
		// esquerda (a)
		if(GetKeyState(65)&0x80) 
		  px -= player_passoX;
	
		// atravessa tela em X
		if (px+32 > telaX) 
	      px = (telaX*0)-player_x;
	    if (px+32 < telaX*0-player_x)
	    	px = telaX-32;
}		

// -------------------------------------------------> boss <-------------------------------------------------
{
// boss sprite
		putimage(bx, by, BM, AND_PUT);
		putimage(bx, by, B, OR_PUT);
		
		// boss movimento alternado - colide X
		for(i = 0; i < 1; i++){
			bx += boss_passoX;
			if (bx <= bx_min || bx >= bx_max-boss_x)
			boss_passoX = -boss_passoX;
		}
		
		// colisao boss <-> player	
		if((px <= bx && bx <= px+player_x) && (py <= by && by <= py+player_y) ||
		   (px <= bx+boss_x && bx <= px+player_x) && (py <= by+boss_y && by <= py+player_y)) {
			hp_col = 1;
		}
}	
	
// --------------------------------------------------> plataformas <------------------------------------------
	
// plataforma inferior
	
	// base	
	for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 0;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}	
		
		}
		}
		
// plataformas esquerda
{
	// 1
		for(i = telainX; i < telaX/14; i+=16){
			floor_vx = 40;
			floor_vy = 510;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	
	// 2
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 180;
			floor_vy = 430;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
	// 3
		for(i = telainX; i < telaX/26; i+=16){
			floor_vx = 10;
			floor_vy = 270;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
	// 4
		for(i = telainX; i < telaX/40; i+=16){
			floor_vx = 220;
			floor_vy = 70;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}	
		
}

// plataformas centro
{
	// 1
		for(i = telainX; i < telaX/18; i+=16){
			floor_vx = 80;
			floor_vy = 540;
			fmov_x = 220;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	
	// 2
		for(i = telainX; i < telaX/46; i+=16){
			floor_vx = 80;
			floor_vy = 480;
			fmov_x = 450;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	// 3
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 80;
			floor_vy = 480;
			fmov_x = 650;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
		
	// 4
		for(i = telainX; i < telaX/8; i+=16){
			floor_vx = 80;
			floor_vy = 290;
			fmov_x = 480;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		

	// 5
		for(i = telainX; i < telaX/34; i+=16){
			floor_vx = 80;
			floor_vy = 185;
			fmov_x = 380;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
	// 6
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 80;
			floor_vy = 170;
			fmov_x = 700;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
}

// plataformas direita
{
	// 1
		for(i = telainX; i < telaX/18; i+=16){
			floor_vx = 650;
			floor_vy = 550;
			fmov_x = 450;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	
	// 2
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 650;
			floor_vy = 450;
			fmov_x = 350;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	// 3
		for(i = telainX; i < telaX/32; i+=16){
			floor_vx = 650;
			floor_vy = 300;
			fmov_x = 250;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
		
	// 4
		for(i = telainX; i < telaX/24; i+=16){
			floor_vx = 650;
			floor_vy = 290;
			fmov_x = 450;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
}
		
// plataforma superior
{
		for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 620;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}		
		}
		
}

// ----------------------------------------------------------> pulo <-----------------------------------------------
{

		// tecla espaco
		if(GetKeyState(32)&0x80)
			pres_esp = 1;
		
		// pulo	
		if (pres_esp == 1 || (py <= teto_h && caindo != 1))
	        py -= pulo;
	    // teto superior
		if (py <= teto_h)
	        caindo = 1;
		// pulo volta	
		if (caindo == 1)
		  	py += pulo+5;
		// teto inferior	
		if (py > teto_l){
		  	caindo = 0;
		  	pres_esp = 0;
		}	
		
}	
	
// ------------------------------------------------------> mov speed / dash <--------------------------------------
{
	
	// tecla shift
	if(GetKeyState(16)&0x80)
		pres_shift = 1;
	

	// direita
	if ((pres_shift == 1) && (GetKeyState(68)&0x80)) {
		player_passoX = 6;
	    px += player_passoX;
	    
		if (px >= (player_passoX*6)+player_x){
	    pres_shift = 0;
	    player_passoX = 4;
		} 
	}
	// esquerda    
	if ((pres_shift == 1) && (GetKeyState(65)&0x80)){
		player_passoX = 6;
		px -= player_passoX;
	
		if (px >= -player_passoX*6){
		pres_shift = 0;
		player_passoX = 4;   
		} 
	}
		
}
	
// --------------------------------------------------------> spell <-----------------------------------------------------
{
	
// spell sprite - main
	
		// posicao inicial
		for(i = 0; i < tam; i++){
			putimage(Spx, Spy, SpM, AND_PUT);
			putimage(Spx, Spy, Sp, OR_PUT);
		}
		
		// spell movimento
		for(i = 0; i < 5; i++){
		
			
			// spell X
			Spx += spell_passoX;
			if (Spx <= zeroX || Spx >= telaX-spell_x){
			spell_passoX = -spell_passoX;
		
			}
			
		
			// spell Y
			Spy += spell_passoY;
			if (Spy <= zeroY || Spy >= telaY-spell_y){
			spell_passoY= -spell_passoY;
			
			}
			
		}
			
		
		// colisao spell <-> player	
		if((px <= Spx && Spx <= px+player_x) && (py <= Spy && Spy <= py+player_y) ||
		   (px <= Spx+spell_x && Spx <= px+player_x) && (py <= Spy+spell_y && Spy <= py+player_y)) {
			hp_col = 1;
		}
		
// spell - centro

	for(i = 0; i < tam; i++){
		putimage(Sp_2x, Sp_2y, SpM, AND_PUT);
		putimage(Sp_2x, Sp_2y, Sp, OR_PUT);		
		
	}
	// spell mov X
		for(i = 0; i < 1; i+=5){
			
			Sp_2x += spell_2_passoX;
			if (Sp_2x <= Sp_2x_min || Sp_2x >= Sp_2x_max-spell_x){
			spell_2_passoX = -spell_2_passoX;
			}
			
	// spell mov Y
			Sp_2y += spell_2_passoY;
			if (Sp_2y <= Sp_2y_min || Sp_2y >= Sp_2y_max-spell_y){
			spell_2_passoY= -spell_2_passoY;
			}
			}
	
	// colisao spell 2 <-> player	
		if((px <= Sp_2x && Sp_2x <= px+player_x) && (py <= Sp_2y && Sp_2y <= py+player_y) ||
		   (px <= Sp_2x+spell_x && Sp_2x <= px+player_x) && (py <= Sp_2y+spell_y && Sp_2y <= py+player_y)) {
			hp_col = 1;
		}
}

// --------------------------------------------------------> HP <----------------------------------------------
{
		
// player hp
		if(hp_col == 1){
			hp_qtd -= 1;
			hp_col = 0;
		}
		
// HP sprite
		// 1
		if (hp_qtd == 1){
		for(i = 0; i < 30; i+=30){
		putimage(hpx+i, hpy, HpM, AND_PUT);
		putimage(hpx+i, hpy, HpS, OR_PUT);
		}
		}
}

// -------------------------------------------------> Frag <----------------------------------------------
{
// fragmento sprite
		if (frag_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(fr_x, fr_y, FrM, AND_PUT);
		putimage(fr_x, fr_y, Fr, OR_PUT);
		}
		}
		
}

// ----------------------------------------------------------> Time Stop <-------------------------------------------
{
	
// time stop sprite	
		if (time_stop_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(TS_x, TS_y, TSM, AND_PUT);
		putimage(TS_x, TS_y, TS, OR_PUT);
		}
		}

// colisao player <-> time stop (retangulo <-> retangulo)
		if((px <= TS_x && TS_x <= px+player_x) && (py <= TS_y && TS_y <= py+player_y) ||
		   (px <= TS_x+time_stop_x && TS_x <= px+player_x) && (py <= TS_y+time_stop_y && TS_y <= py+player_y)){
			spell_passoX = 0;
			spell_passoY = 0;
			time_stop_qtd = 0;
		}		
	
}

		
// --------------------------------------------------> fragmento 2 colisao <----------------------------------------------
{
	// colisao player <-> fragmento (retangulo <-> retangulo)
		if((px <= fr_x && fr_x <= px+player_x) && (py <= fr_y && fr_y <= py+player_y) || (px <= fr_x+frag_x && fr_x <= px+player_x) && (py <= fr_y+frag_y && fr_y <= py+player_y)) {
			frag_qtd_obt = 2;
			}		
}


		
// --------------------------------------------------> Fase 3 (obter 2 fragmentos) <----------------------------------------------
{
	// colisao player <-> fragmento (retangulo <-> retangulo)
		if (frag_qtd_obt == 2){
		if((px <= fr_x && fr_x <= px+player_x) && (py <= fr_y && fr_y <= py+player_y) ||
		   (px <= fr_x+frag_x && fr_x <= px+player_x) && (py <= fr_y+frag_y && fr_y <= py+player_y)) {
			Level_3();
		}		
		}
}

// ---------------------------------------------------> Game over <-------------------------------------
{		
		if (hp_qtd == 0){
//			mciSendString("open .\\sons\\laugh_death2.mp3 type MPEGVideo alias repetido", NULL, 0, 0);
//			sndPlaySound(".\\sons\\hit_skill.wav", SND_ASYNC);
//			delay (250);
//			sndPlaySound(".\\sons\\laugh_death1.wav", SND_SYNC);
			Game_Over();
		}
		
}		
		setvisualpage(pg);

	//	delay(1);
	}
	fflush(stdin);  
	
	
// comando teclas
 		if (kbhit()){
     		tecla = getch();
   		
   			//ESC
			if(tecla == 27)
		 		exit(0);
		}
	}

}

void Level_3(){
// --------------------------------------------------> variaveis <-------------------------------------------
		
	// tam	
	int i, j, TamB, TamF, TamSp, TamHp, TamFr, TamDash, TamBG, TamTS, line,  TamFr2;
	
	// resoluçao tela
	telaX = 1280, telaY = 720; 
	zeroX = 0, zeroY = 0;
	
	
	int pg = 2;
	char tecla = 0;
	int cont, tam = 1;
	
	Tmain *main;

	main = (Tmain *)malloc(sizeof(Tmain) * tam);

	// BGM - fase 1	

	//sndPlaySound(NULL, NULL);
	mciSendString("stop intro", NULL, 0, 0); // pára a reprodução do alias repetido
//	sndPlaySound(".\\sons\\sound_scene2.wav", SND_ASYNC + SND_LOOP);
	

// -----------------------------------------> sprite tam <--------------------------------------------------
	
	// player sprite img
	player_x = 64;
	player_y = 64;
	player_passoX = 4;
	player_passoY = 0;
	
	// boss sprite img
	boss_x = 64;
	boss_y = 64;
	bx_min = 350;
	bx_max = 900;
	by_min = 0;
	by_max = 700;
	boss_passoX = 2;
	boss_passoY = 8;
	
	// floor sprite img
	floor_x = 16;
	floor_y = 16;
	floor_passoX = 0;
	floor_passoY = 0;
	floor_vx = 0;
	floor_vy = 0;
	fmov_x = 0;
	fmov_y = 0;
	floor_effect = 0;
	
	// spell sprite img
	spell_x = 32;
	spell_y = 32;
	spell_passoX = 0;
	spell_passoY = 8;
	Sp_cont = 0;
	
	// spell 2
	spell_2_passoX = 0;
	spell_2_passoY = 24;
	Sp_2x_min = zeroX;
	Sp_2x_max = telaX-spell_x;
	Sp_2y_min = zeroY;
	Sp_2y_max = telaY-spell_y;

	// background img - fase 1
	bg_1x = 1280;
	bg_1y = 720;
	
	// frag sprite img
	frag_x = 32;
	frag_y = 32;
	frag_passoX = 0;
	frag_passoY = 0;
	
	// hp sprite img
	hp_x = 32;
	hp_y = 32;
	hp_qtd = 1;
	hp_col = 0;
	
	// pulo
	pulo = 5;
	tam_pulo = 195;
	teto_b = 0;
	caindo = 0;
	pres_esp = 0;
	
	// dash sprite
	dash_x = 32;
	dash_y = 32;
	
	// dash / mov speed
	pres_shift = 0;
	dash_qtd = 2;
	dash_cd = 0;
	cd_timer = 0;
	
	// time stop 
	time_stop_x = 64;
	time_stop_y = 64;
	time_stop_qtd = 1;

// ---------------------------------------------> tela grafica <------------------------------------------------------
	
	setbkcolor(RGB(0, 20, 50));
	
// --------------------------------------------> background fase 1 <-----------------------------------------
	
	// bg img
	TamBG = imagesize(0, 0, telaX-1, telaY-1);
	BG = malloc(TamBG);

	// bg sprite 
	readimagefile("image/main/bg_1.bmp", 0, 0, bg_1x-1, bg_1y-1);
	getimage(0, 0, bg_1x-1, bg_1y-1, BG);
	 
// --------------------------------------------> player <------------------------------------------------
	
	// player - img 
	for (i = 0; i < tam; i++){
		main[i].tam_main = imagesize(0, 0, player_x-1, player_y-1);
		S = malloc(main[i].tam_main);
		SM = malloc(main[i].tam_main);
	}
	// player - sprite
	readimagefile("image/main/player_sprite.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, S);
	
	// player - mask  
	readimagefile("image/main/player_mask.bmp", 0, 0, player_x-1, player_y-1);
	getimage(0, 0, player_x-1, player_y-1, SM);
	
	// player - spawn
	px = telainX+50;
	py = telainY;
	
// -----------------------------------------------> boss <----------------------------------------------
	
	// boss - img
	TamB = imagesize(0, 0, boss_x-1, boss_y-1);
	B = malloc(TamB);
	BM = malloc(TamB);
	
	// boss - sprite
	readimagefile("image/boss/boss_sprite.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, B);
	
	// boss - mask
	readimagefile("image/boss/boss_mask.bmp", 0, 0, boss_x-1, boss_y-1);
	getimage(0, 0, boss_x-1, boss_y-1, BM);
	
	// boss - spawn
	bx = telaX/2;
	by = 450;
	
// -----------------------------------------> floor/plataforma <-----------------------------------------

	// flor - img
	TamF = imagesize(0, 0, floor_x-1, floor_y-1);
	F = malloc(TamF);

	// flor - sprite
	readimagefile("image/elements/floor_sprite.bmp", 0, 0, floor_x-1, floor_y-1);
	getimage(0, 0, floor_x-1, floor_y-1, F);
	
	// flor - spawn
	fx = zeroX+1;
	fy = telaY-floor_y-5;
	
// ------------------------------------------------> pulo/teto <-----------------------------------------	

	teto_h = (fy-floor_vy)-(tam_pulo);
	teto_l = (fy-floor_vy)-player_y-pulo;
	
// ----------------------------------------------> spell <---------------------------------------------------

	// spell - img  
	TamSp = imagesize(0, 0, spell_x-1, spell_y-1);
	Sp = malloc(TamSp);
	SpM = malloc(TamSp);
	
	// spell - sprite
	readimagefile("image/boss_magic/spell_sprite.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, Sp);
	
	// spell - mask
	readimagefile("image/boss_magic/spell_mask.bmp", 0, 0, spell_x-1, spell_y-1);
	getimage(0, 0, spell_x-1, spell_y-1, SpM);
	
	// spell - spawn
	Spx = 10;
	Spy = 10+spell_y;
	
	Sp_2x = telaX-spell_x-10;
	Sp_2y = telainY+spell_y;
	
// --------------------------------------------> fragmento <----------------------------------------------
	
	// frag - img
	TamFr = imagesize(0, 0, frag_x-1, frag_y-1);
	Fr = malloc(TamFr);
	FrM = malloc(TamFr);	
		
	// frag - sprite
	readimagefile("image/elements/frag_sprite.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, spell_y-1, Fr);
	
	// frag - mask
	readimagefile("image/elements/frag_mask.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, frag_y-1, FrM);
	
	// frag - spawn
	fr_x = telaX/2-50;
	fr_y = telaY/2+50;
	frag_qtd = 1;
	frag_qtd_obt = 2;
	
// --------------------------------------------> fragmento 2 <----------------------------------------------
	
	// frag 2 - img
	TamFr2 = imagesize(0, 0, frag_x-1, frag_y-1);
	Fr2 = malloc(TamFr2);
	FrM2 = malloc(TamFr2);	
		
	// frag 2 - sprite
	readimagefile("image/elements/frag_2_sprite.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, spell_y-1, Fr2);
	
	// frag 2 - mask
	readimagefile("image/elements/frag_2_mask.bmp", 0, 0, frag_x-1, frag_y-1);
	getimage(0, 0, frag_x-1, frag_y-1, FrM2);
	
	// frag 2 - spawn
	fr_2x = 300;
	fr_2y = fy-frag_y-250;
	frag_2_qtd = 0;
	frag_2_qtd_obt = 0;
	frag_vx = 0;
	frag_vy = 0;
	
// -------------------------------------------> time stop <----------------------------------------------

	// time stop - img
	TamTS = imagesize(0, 0, time_stop_x-1, time_stop_y-1);
	TS = malloc(TamTS);
	TSM = malloc(TamTS);	
		
	// time stop - sprite
	readimagefile("image/elements/time_stop_sprite.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TS);
	
	// time stop - mask
	readimagefile("image/elements/time_stop_mask.bmp", 0, 0, time_stop_x-1, time_stop_y-1);
	getimage(0, 0, time_stop_x-1, time_stop_y-1, TSM);

	// time stop - spawn
	TS_x = 610;
	TS_y = 350;
	
// -------------------------------------------------> HP <---------------------------------------------------

	// HP - img
	TamHp = imagesize(0, 0, hp_x-1, hp_y-1);
	HpS = malloc(TamHp);
	HpM = malloc(TamHp);
	
	// HP - sprite
	readimagefile("image/hud/hp_sprite.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpS);
	
	// HP - mask
	readimagefile("image/hud/hp_mask.bmp", 0, 0, hp_x-1, hp_y-1);
	getimage(0, 0, hp_x-1, hp_y-1, HpM);
	
	// HP - spawn
	hpx = 0;
	hpy = telaY-hp_y-20;
	
	
// -------------------------------------------> loop principal <---------------------------------------------

	while(tecla != 27){
		gt2 = GetTickCount();
		if (gt2-gt1 > 1000/70){ 
		gt1 = gt2;
    	if (pg == 1) pg = 2; else pg=1;
    
		setactivepage(pg);
    	cleardevice();
		
// background - fase 1
    	putimage(telainX, telainY, BG, COPY_PUT);
	
// ----------------------------------------------> player <------------------------------------------------	
{
// player sprite
		putimage(px, py, SM, AND_PUT);
		putimage(px, py, S, OR_PUT);
			
		// player img - comandos teclado
		
		// direita (d)
		if(GetKeyState(68)&0x80) 
		  px += player_passoX;
		// esquerda (a)
		if(GetKeyState(65)&0x80) 
		  px -= player_passoX;
	
		// atravessa tela em X
		if (px+32 > telaX) 
	      px = (telaX*0)-player_x;
	    if (px+32 < telaX*0-player_x)
	    	px = telaX-32;
}		

// -------------------------------------------------> boss <-------------------------------------------------
{
// boss sprite
		if(frag_2_qtd_obt != 4){
		putimage(bx, by, BM, AND_PUT);
		putimage(bx, by, B, OR_PUT);
		}
		
		// boss movimento alternado - colide X e Y
		for(i = 0; i < tam; i++){
			
			bx += boss_passoX;
			if (bx <= bx_min || bx >= bx_max-boss_x)
			boss_passoX = -boss_passoX;
					
			by += boss_passoY;
			if (by <= by_min || by >= by_max-boss_y)
			boss_passoY = -boss_passoY;
		}
		
		// colisao boss <-> player	
		if((px <= bx && bx <= px+player_x) && (py <= by && by <= py+player_y) ||
		   (px <= bx+boss_x && bx <= px+player_x) && (py <= by+boss_y && by <= py+player_y)) {
			hp_col = 1;
		}
				
}	
	
// --------------------------------------------------> plataformas <------------------------------------------
	
// plataforma inferior
	
	// base	
	for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 0;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
				
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			floor_effect = 0;
			py = (fy-floor_vy-player_y);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}	
		
		}
		}


// plataformas centro
{
	// 1
		for(i = telainX; i < telaX/36; i+=16){
			floor_vx = 420;
			floor_vy = 120;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			floor_effect = 1;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	
	// 2
		for(i = telainX; i < telaX/36; i+=16){
			floor_vx = 420;
			floor_vy = 120;
			fmov_x = 300;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			floor_effect = 1;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	// 3
	if (floor_effect >= 1){
		for(i = telainX; i < telaX/42; i+=16){
			floor_vx = 250;
			floor_vy = 250;
			fmov_x = 50;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			floor_effect = 2;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	}
		
	// 4
	if (floor_effect >= 1){
		for(i = telainX; i < telaX/42; i+=16){
			floor_vx = 250;
			floor_vy = 250;
			fmov_x = 600;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			floor_effect = 2;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	}

	// 5
	if(floor_effect >= 2){
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 420;
			floor_vy = 380;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	}
		
	// 6
	if(floor_effect >= 2){
		for(i = telainX; i < telaX/20; i+=16){
			floor_vx = 420;
			floor_vy = 380;
			fmov_x = 300;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);

		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}	
	
		}
		}
	}
		
}


/*		
// plataforma superior
{
		for(i = 0; i < telaX; i+=16){
			floor_vx = 0;
			floor_vy = 620;
			fmov_x = 0;
			putimage(fx+i+floor_vx+fmov_x, fy-floor_vy, F, COPY_PUT);
		// colisao 
		if ((px <= (fx+i+floor_vx+fmov_x) && (fx+i+floor_vx+fmov_x)<= px+player_x) && py+player_y == (fy-floor_vy)){
			caindo = 0;
			py = (fy-floor_vy-player_y+pulo);
			teto_h = fy-floor_vy-tam_pulo;
			
		// pulo
			if(GetKeyState(32)&0x80){
				py -= pulo;	
			}
					
		// descer plataforma	
			if(GetKeyState(83)&0x80){
				caindo = 1;	
			}
		}		
		}
		
}
*/

// ----------------------------------------------------------> pulo <-----------------------------------------------
{

		// tecla espaco
		if(GetKeyState(32)&0x80)
			pres_esp = 1;
		
		// pulo	
		if (pres_esp == 1 || (py <= teto_h && caindo != 1))
	        py -= pulo;
	    // teto superior
		if (py <= teto_h)
	        caindo = 1;
		// pulo volta	
		if (caindo == 1)
		  	py += pulo+5;
		// teto inferior	
		if (py > teto_l){
		  	caindo = 0;
		  	pres_esp = 0;
		}	
		
}	
	
// ------------------------------------------------------> mov speed / dash <--------------------------------------
{
	
	// tecla shift
	if(GetKeyState(16)&0x80)
		pres_shift = 1;
	

	// direita
	if ((pres_shift == 1) && (GetKeyState(68)&0x80)) {
		player_passoX = 6;
	    px += player_passoX;
	    
		if (px >= (player_passoX*6)+player_x){
	    pres_shift = 0;
	    player_passoX = 4;
		} 
	}
	// esquerda    
	if ((pres_shift == 1) && (GetKeyState(65)&0x80)){
		player_passoX = 6;
		px -= player_passoX;
	
		if (px >= -player_passoX*6){
		pres_shift = 0;
		player_passoX = 4;   
		} 
	}
		
}
	
// --------------------------------------------------------> spell <-----------------------------------------------------
{
	
// spell sprite - esquerda
	
		// posicao inicial
		for(i = 0; i < tam; i++){
			putimage(Spx, Spy, SpM, AND_PUT);
			putimage(Spx, Spy, Sp, OR_PUT);
		}
		
		// spell movimento
		for(i = 0; i < 5; i++){
		
			
			// spell X
			Spx += spell_passoX;
			if (Spx <= zeroX || Spx >= telaX-spell_x){
			spell_passoX = -spell_passoX;
		
			}
			
		
			// spell Y
			Spy += spell_passoY;
			if (Spy <= zeroY || Spy >= telaY-spell_y){
			spell_passoY= -spell_passoY;
			
			}
			
		}
			
		
		// colisao spell <-> player	
		if((px <= Spx && Spx <= px+player_x) && (py <= Spy && Spy <= py+player_y) ||
		   (px <= Spx+spell_x && Spx <= px+player_x) && (py <= Spy+spell_y && Spy <= py+player_y)) {
			hp_col = 1;
		}
		
// spell - direita

	for(i = 0; i < tam; i++){
		putimage(Sp_2x, Sp_2y, SpM, AND_PUT);
		putimage(Sp_2x, Sp_2y, Sp, OR_PUT);		
		
	}
	// spell mov X
		for(i = 0; i < tam; i++){
			
			Sp_2x += spell_2_passoX;
			if (Sp_2x <= Sp_2x_min || Sp_2x >= Sp_2x_max-spell_x){
			spell_2_passoX = -spell_2_passoX;
			}
			
	// spell mov Y
			Sp_2y += spell_2_passoY;
			if (Sp_2y <= Sp_2y_min || Sp_2y >= Sp_2y_max-spell_y){
			spell_2_passoY= -spell_2_passoY;
			}
			}
	
	// colisao spell 2 <-> player	
		if((px <= Sp_2x && Sp_2x <= px+player_x) && (py <= Sp_2y && Sp_2y <= py+player_y) ||
		   (px <= Sp_2x+spell_x && Sp_2x <= px+player_x) && (py <= Sp_2y+spell_y && Sp_2y <= py+player_y)) {
			hp_col = 1;
		}

}

// --------------------------------------------------------> HP <----------------------------------------------
{
		
// player hp
		if(hp_col == 1){
			hp_qtd -= 1;
			hp_col = 0;
		}
		
// HP sprite
		// 1
		if (hp_qtd == 1){
		for(i = 0; i < 30; i+=30){
		putimage(hpx+i, hpy, HpM, AND_PUT);
		putimage(hpx+i, hpy, HpS, OR_PUT);
		}
		}
}

// -------------------------------------------------> Frag <----------------------------------------------
{
// fragmento sprite
	if (frag_2_qtd_obt >= 4){
		if (frag_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(fr_x, fr_y, FrM, AND_PUT);
		putimage(fr_x, fr_y, Fr, OR_PUT);
		}
		}
	}
		
}


// -----------------------------------------------> fragmento 2 <-------------------------------------------------------
	
	//1
		if ((floor_effect >= 1) && (frag_2_qtd_obt == 0)){
			for(i = 0; i < tam ; i++){
	
			putimage(fr_2x, fr_2y, FrM2, AND_PUT);
			putimage(fr_2x, fr_2y, Fr2, OR_PUT);
			}
		// colisao player <-> fragmento (retangulo <-> retangulo)
			if((px <= fr_2x && fr_2x <= px+player_x) && (py <= fr_2y && fr_2y <= py+player_y) ||
			   (px <= fr_2x+frag_x && fr_2x <= px+player_x) && (py <= fr_2y+frag_y && fr_2y <= py+player_y)) {
				frag_2_qtd_obt = 1;
				}
			
		}
		
	// 2	
		if ((floor_effect >= 2) && (frag_2_qtd_obt == 1)){
			for(i = 0; i < tam ; i++){
			frag_vx = 135;
			frag_vy = 150;
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, FrM2, AND_PUT);
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, Fr2, OR_PUT);
			}
		// colisao player <-> fragmento (retangulo <-> retangulo)
			if((px <= fr_2x+frag_vx && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy && fr_2y-frag_vy <= py+player_y) ||
			   (px <= fr_2x+frag_vx+frag_x && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy+frag_y && fr_2y-frag_vy <= py+player_y)) {
				frag_2_qtd_obt = 2;
				}
			
		}
	// 3	
		if ((floor_effect >= 2) && (frag_2_qtd_obt == 2)){
			for(i = 0; i < tam ; i++){
			frag_vx = 435;
			frag_vy = 150;
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, FrM2, AND_PUT);
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, Fr2, OR_PUT);
			}
		// colisao player <-> fragmento (retangulo <-> retangulo)
			if((px <= fr_2x+frag_vx && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy && fr_2y-frag_vy <= py+player_y) ||
			   (px <= fr_2x+frag_vx+frag_x && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy+frag_y && fr_2y-frag_vy <= py+player_y)) {
				frag_2_qtd_obt = 3;
				}
			
		}
	// 4	
		if ((floor_effect >= 1) && (frag_2_qtd_obt == 3)){
			for(i = 0; i < tam ; i++){
			frag_vx = 550;
			frag_vy = 0;
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, FrM2, AND_PUT);
			putimage(fr_2x+frag_vx, fr_2y-frag_vy, Fr2, OR_PUT);
			}
		// colisao player <-> fragmento (retangulo <-> retangulo)
			if((px <= fr_2x+frag_vx && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy && fr_2y-frag_vy <= py+player_y) ||
			   (px <= fr_2x+frag_vx+frag_x && fr_2x+frag_vx <= px+player_x) && (py <= fr_2y-frag_vy+frag_y && fr_2y-frag_vy <= py+player_y)) {
				frag_2_qtd_obt = 4;
				}
			
		}
		
	

// ----------------------------------------------------------> Time Stop <-------------------------------------------
{
	
// time stop sprite	
	if(frag_2_qtd_obt != 4){
		if (time_stop_qtd == 1){
		for (i = 0; i < tam; i++){
		putimage(TS_x-50, TS_y, TSM, AND_PUT);
		putimage(TS_x-50, TS_y, TS, OR_PUT);
		}
		}
	}

// colisao player <-> time stop (retangulo <-> retangulo)
	if(frag_2_qtd_obt != 4){
		if((px <= TS_x && TS_x <= px+player_x) && (py <= TS_y && TS_y <= py+player_y) ||
		   (px <= TS_x+time_stop_x && TS_x <= px+player_x) && (py <= TS_y+time_stop_y && TS_y <= py+player_y)){
			spell_passoX = 0;
			spell_passoY = 0;
			time_stop_qtd = 0;
		}		
	}
}

		
// --------------------------------------------------> fragmento 3 colisao <----------------------------------------------
{
	// colisao player <-> fragmento (retangulo <-> retangulo)
	if (frag_2_qtd_obt == 4){
		if((px <= fr_x && fr_x <= px+player_x) && (py <= fr_y && fr_y <= py+player_y) || (px <= fr_x+frag_x && fr_x <= px+player_x) && (py <= fr_y+frag_y && fr_y <= py+player_y)) {
			frag_qtd_obt = 3;
			}		
	}
}


		
// --------------------------------------------------> End (obter 3 fragmentos) <----------------------------------------------
{
	// colisao player <-> fragmento (retangulo <-> retangulo)
		if (frag_qtd_obt == 3){
		if((px <= fr_x && fr_x <= px+player_x) && (py <= fr_y && fr_y <= py+player_y) ||
		   (px <= fr_x+frag_x && fr_x <= px+player_x) && (py <= fr_y+frag_y && fr_y <= py+player_y)) {
			End();
		}
	}
}

// ---------------------------------------------------> Game over <-------------------------------------
{		
		if (hp_qtd == 0){
//			mciSendString("open .\\sons\\laugh_death2.mp3 type MPEGVideo alias repetido", NULL, 0, 0);
//			sndPlaySound(".\\sons\\hit_skill.wav", SND_ASYNC);
//			delay (250);
//			sndPlaySound(".\\sons\\laugh_death1.wav", SND_SYNC);
			Game_Over();
		}
		
}		
		setvisualpage(pg);

	//	delay(1);
	}
	fflush(stdin);  
	
	
// comando teclas
 		if (kbhit()){
     		tecla = getch();
   		
   			//ESC
			if(tecla == 27)
		 		exit(0);
		}
	}	
}

#include "DxLib.h"
#include "game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウィンドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		// 画面のクリア
		ClearDrawScreen();
		
		DrawString(160, 160, "Git test くらんきーちょこなかはるきっず", GetColor(255, 255, 255));
		DrawString(160, 180, "おやおや、おやおやおやおや", GetColor(255, 255, 255));
		DrawString(160, 200, "あなた、覗きましたね？", GetColor(255, 255, 255));
		DrawString(160, 220, "りんはかわいい", GetColor(255, 255, 255));

		// 裏画面を表画面と入れ替える
		ScreenFlip();
		
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
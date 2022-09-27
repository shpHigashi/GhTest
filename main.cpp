#include "DxLib.h"
#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�B���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʂ̃N���A
		ClearDrawScreen();
		
		DrawString(160, 160, "Git test �Ȃ��͂邫����", GetColor(255, 255, 255));
		DrawString(160, 180, "����Ղ�N������", GetColor(255, 255, 255));

		// ����ʂ�\��ʂƓ���ւ���
		ScreenFlip();
		
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
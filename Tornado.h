#pragma once
#undef UNICODE  // Unicode�ł͂Ȃ��A�}���`�o�C�g�������g��
#include<Windows.h>
#include<d3d11.h>
#include<dxgi.h>
#include"WICTextureLoader.h"

#define TORUNADOSPEED 0.01f
#define SIZEW    0.25f
#define SIZEH    1.0f

struct VERTEX2D   // VERTEX = ���_
{
	float x, y;  // ���_�̍��W�i�ʒu�j
	float u, v;  // �e�N�X�`����UV���W
};

class CTORNADO
{
private:
	//============================================
	// �����o�ϐ�
	//============================================
	wchar_t*                                m_tex;			//�e�N�X�`���[�̖��O
	ID3D11Device*							m_device;		//�f�o�C�X�̃|�C���^
	ID3D11DeviceContext*					m_context;		//�f�o�C�X�R���e�L�X�g�̃|�C���^
	ID3D11ShaderResourceView*				m_SRV;			//�V�F�[�_�[���\�[�X�̃|�C���^

	ID3D11VertexShader*						m_VS;			//���_�V�F�[�_�[�̃|�C���^
	ID3D11PixelShader*						m_PS;			//�s�N�Z���V�F�[�_�[�̃|�C���^
	ID3D11InputLayout*						m_InputLayout;	//�C���v�b�g���C�A�E�g�̃|�C���^
	ID3D11Buffer*                           m_VB;			//���_�o�b�t�@�̃|�C���^
	ID3D11SamplerState*                     m_Sampler;		//�T���v���[�̃|�C���^
	
	float									m_PosX;			//�摜�̐^�񒆂̃|�W�V����X
	float									m_PosY;			//�摜�̐^�񒆂̃|�W�V����Y
	float									m_SizeW;		//�摜�̃T�C�YW
	float									m_SizeH;		//�摜�̃T�C�YH


	//============================================
	// �����o�֐�
	//============================================
	BOOL LoadTex();

public:
	//�R���X�g���N�^
	CTORNADO(wchar_t* _Tex ,ID3D11Device* _pDevice, ID3D11DeviceContext* _pDeviceContext, ID3D11ShaderResourceView* _pShaderResourceView,
		ID3D11VertexShader* _pVS, ID3D11PixelShader* _pPS, ID3D11InputLayout* _pInputLayout, ID3D11Buffer* _pVB, ID3D11SamplerState* _pSampler);

	//�|�W�V�����ƃT�C�Y���擾����֐�
	void GetPosAndSize(float *_PosX,float *_PosY, float *SizeW,float* _SizeH);
	//�����������@�@����񂾂����s���Ă�������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

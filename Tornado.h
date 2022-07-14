#pragma once
#undef UNICODE  // Unicodeではなく、マルチバイト文字を使う
#include<Windows.h>
#include<d3d11.h>
#include<dxgi.h>
#include"WICTextureLoader.h"

#define TORUNADOSPEED 0.01f
#define SIZEW    0.25f
#define SIZEH    1.0f

struct VERTEX2D   // VERTEX = 頂点
{
	float x, y;  // 頂点の座標（位置）
	float u, v;  // テクスチャのUV座標
};

class CTORNADO
{
private:
	//============================================
	// ウンチ？？
	//============================================
	wchar_t*                                m_tex;			//テクスチャーの名前
	ID3D11Device*							m_device;		//デバイスのポインタ
	ID3D11DeviceContext*					m_context;		//デバイスコンテキストのポインタ
	ID3D11ShaderResourceView*				m_SRV;			//シェーダーリソースのポインタ

	ID3D11VertexShader*						m_VS;			//頂点シェーダーのポインタ
	ID3D11PixelShader*						m_PS;			//ピクセルシェーダーのポインタ
	ID3D11InputLayout*						m_InputLayout;	//インプットレイアウトのポインタ
	ID3D11Buffer*                           m_VB;			//頂点バッファのポインタ
	ID3D11SamplerState*                     m_Sampler;		//サンプラーのポインタ
	
	float									m_PosX;			//画像の真ん中のポジションX
	float									m_PosY;			//画像の真ん中のポジションY
	float									m_SizeW;		//画像のサイズW
	float									m_SizeH;		//画像のサイズH


	//============================================
	// メンバ関数
	//============================================
	BOOL LoadTex();

public:
	//コンストラクタ
	CTORNADO(wchar_t* _Tex ,ID3D11Device* _pDevice, ID3D11DeviceContext* _pDeviceContext, ID3D11ShaderResourceView* _pShaderResourceView,
		ID3D11VertexShader* _pVS, ID3D11PixelShader* _pPS, ID3D11InputLayout* _pInputLayout, ID3D11Buffer* _pVB, ID3D11SamplerState* _pSampler);

	//ポジションとサイズを取得する関数
	void GetPosAndSize(float *_PosX,float *_PosY, float *SizeW,float* _SizeH);
	//初期化処理　　＊一回だけ実行してください
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

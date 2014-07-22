#pragma once
#include "../../vmdefine.h"


namespace SenchaVM {
namespace Assembly {
using namespace std;

enum ERR_ID {
	// 1000��
	// ���]���G���[
	ERROR_1001 , // �Q�ƌ^�ɑ���ȊO�̃f�[�^���߂������Ă���
	ERROR_1002 , // ���ӂ��Q�ƌ^�ł���ꍇ�A�E�ӂ͑Ή�����f�[�^�����łȂ���΂����Ȃ�

	// 2000��
	// �V���^�b�N�X�G���[
	ERROR_2001 , // '['�ɑΉ�����L��']'��������Ȃ�
	ERROR_2002 , // '('�ɑΉ�����L��')'��������Ȃ�
	ERROR_2003 , // '{'�ɑΉ�����L��'}'��������Ȃ�

	// 3000��
	// �錾�G���[
	ERROR_3001 , // �\���̓����Ŋ֐��錾���ꂽ
	ERROR_3002 , // �������O�̊֐������ɓo�^�ς݂ł���

	// 4000��
	// �V���{���G���[
	ERROR_4001 , // �s���ȃV���{���^�C�v
};

/*
 * �G���[�񋓌^�̊g���@�\
 */
class ERR_ID_EX{
public :
	/*
	 * �h�c�𕶎���ɂ���
	 */
	static string toString( ERR_ID value );
};

/*
 * �G���[���̃p�����[�^���
 * �G���[�̎�ނɂ���ė~�����p�����[�^���قȂ�̂Œ��ۓI�ɃI�u�W�F�N�g�̂ݗp�ӂ���
 */
class VMErrorParameter {
public :
	ERR_ID errId;
public :
	VMErrorParameter( ERR_ID errid ){
		this->errId = errid;
	}
	virtual ~VMErrorParameter(){
	}
};

/* 
 * �\���̓����Ŋ֐��錾���ꂽ
 */
class ERROR_INFO_3001 : public VMErrorParameter {
public :
	string funcName;
	ERROR_INFO_3001( string funcName ) : VMErrorParameter( ERROR_3001 ){
		this->funcName = funcName;
	}
};


/* 
 * �s���ȃV���{���^�C�v
 */
class ERROR_INFO_4001 : public VMErrorParameter {
public :
	string symbolName;
	ESymbolType symbolType;
	ERROR_INFO_4001( string symbolName , ESymbolType symbolType ) : VMErrorParameter( ERROR_4001 ){
		this->symbolName = symbolName;
		this->symbolType = symbolType;
	}
};

/*
 * ���z�@�B�֌W�ł̃G���[�����Ȃ�
 */
class VMError {
protected :
	string m_message;
	VMErrorParameter* m_param;
public :
	VMError( VMErrorParameter* param );
	virtual ~VMError();
	const string& getMessage(){
		return m_message;
	}
};


}
}
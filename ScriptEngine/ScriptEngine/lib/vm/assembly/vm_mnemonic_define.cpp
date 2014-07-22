#include "vm_mnemonic_define.h"
#include "../vmdefine.h"

namespace SenchaVM{
namespace Assembly{
string EMnemonic::toString( int mnemonic ){
#define MATCH( symbol ) case symbol : return TO_STRING( symbol );
	switch( mnemonic ){
	MATCH(PMov)
	MATCH(Mov)
	MATCH(Add) 
	MATCH(Sub)
	MATCH(Mul) 
	MATCH(Div)
	MATCH(Rem)
	MATCH(Push)
	MATCH(Call) 
	MATCH(EndFunc)
	MATCH(CmpGeq)
	MATCH(CmpG)
	MATCH(CmpLeq) 
	MATCH(CmpL) 
	MATCH(CmpEq) 
	MATCH(CmpNEq) 
	MATCH(LogOr)
	MATCH(LogAnd)
	MATCH(Jne)
	MATCH(Jnge) 
	MATCH(Jng) 
	MATCH(Jnle) 
	MATCH(Jnl)
	MATCH(Je)
	MATCH(Jge) 
	MATCH(Jg) 
	MATCH(Jle) 
	MATCH(Jl)
	MATCH(Jmp)
	MATCH(JumpZero)
	MATCH(JumpNotZero)
	MATCH(REG)
	MATCH(LIT_VALUE)
	MATCH(LIT_STRING)
	MATCH(MEM_L)
	MATCH(MEM_S)
	MATCH(RET)
	MATCH(MEM_THIS_P)
	MATCH(ArrayIndexSet)
	MATCH(ArrayIndexAdd)
	}
#undef MATCH
	return "unknown";
}


} // namespace Assembly
} // namespace SenchaVM

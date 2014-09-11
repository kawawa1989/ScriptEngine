#include "lib\vm\sencha_vm.h"
#include "lib\vm\assembly\vm_assemble_log.h"
#include "lib\vm\assembly\vm_assemble_io.h"

using namespace SenchaVM;
using namespace SenchaVM::Assembly;
using namespace Sencha::Util;

void ReadScriptAndWriteBinary();
void ReadScriptAndWriteTextFileLog();
void ReadBinaryAndWriteTextFileLog();


void built_in_function_Log( VMDriver* driver ){
	string message = driver->popMemory().value_string;
	std::cout << message << std::endl;
}
void built_int_function_ToString( VMDriver* driver ){
	Memory& m = driver->popMemory();
	static char buf[512];
	sprintf_s<512>( buf , "%.f" , m.value );
	R_STACK::setMemory( 0 , Memory( 0 , buf ) );
}


void main(){
//	ReadScriptAndWriteBinary();
//	ReadScriptAndWriteTextFileLog();
//	ReadBinaryAndWriteTextFileLog();

	Log* log = new ConsoleLog();
	VMBuiltIn* built_in = new VMBuiltIn();
	built_in->entryFunction( new VMBuiltInFunction( "Log" , built_in_function_Log ) );
	built_in->entryFunction( new VMBuiltInFunction( "ToString" , built_int_function_ToString ) );

	Lexer* lexer = new Lexer( CStream( new FileStream( "sample/FizzBuzz.txt" ) ) );
	Parser* parser = new Parser( lexer , built_in , log );
	VMAssembleTextFileLog( parser , "parser_log.txt" );
	VMDriver d( parser , built_in );
	d.executeFunction( "main" );

	delete lexer;
	delete parser;
	delete log;
	delete built_in;
}

// ---------------------------------------------------------------
// スクリプトファイル解析後、バイナリ書き込み
// ---------------------------------------------------------------
void ReadScriptAndWriteBinary(){
	Log* log = new ConsoleLog();
	VMBuiltIn* built_in = new VMBuiltIn();
	built_in->entryFunction( new VMBuiltInFunction( "Log" , built_in_function_Log ) );

	Lexer* lexer = new Lexer( CStream( new FileStream( "sample/FizzBuzz.txt" ) ) );
	Parser* parser = new Parser( lexer , built_in , log );

	VMAssembleOutput output( parser , "parser_data.bin" );

	delete lexer;
	delete parser;
	delete log;
	delete built_in;
}

// ---------------------------------------------------------------
// スクリプトファイル解析後、コマンドリストをテキストに
// ---------------------------------------------------------------
void ReadScriptAndWriteTextFileLog(){
	Log* log = new ConsoleLog();
	VMBuiltIn* built_in = new VMBuiltIn();
	built_in->entryFunction( new VMBuiltInFunction( "Log" , built_in_function_Log ) );

	Lexer* lexer = new Lexer( CStream( new FileStream( "sample/FizzBuzz.txt" ) ) );
	Parser* parser = new Parser( lexer , built_in , log );

	VMAssembleTextFileLog( parser , "parser_log.txt" );
	delete lexer;
	delete parser;
	delete log;
	delete built_in;
}

// ---------------------------------------------------------------
// バイナリ読み込み後、コマンドリストをテキストに
// ---------------------------------------------------------------
void ReadBinaryAndWriteTextFileLog(){
	VMAssembleInput input( CStream( new FileStream( "parser_data.bin" ) ) );
	VMAssembleTextFileLog( &input , "parser_data_out.txt" );
}


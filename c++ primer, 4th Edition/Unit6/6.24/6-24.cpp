#include <iostream>
#include <string>
#include <bitset>
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
	try
	{
		string s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
		bitset<64> bitvec(s);
		bitvec.to_ulong();
	}
	catch (overflow_error err)
	{
		cout<<err.what()<<endl<<"error inside"<<endl;
	}
}
#include "testlib.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;


string escape(string s) {
	stringstream res;
	res << hex;
	for (unsigned i = 0; i < s.length(); i++) {
		res << (i > 0 ? " " : "") 
			<< setw(2) << setfill('0') << uppercase << ((unsigned) ((256+s[i])%256));
	}
	return res.str();
}


int main(int argc, char * argv[])
{
	setName("compare files as a single line, printing character hex codes if wrong");
	registerTestlibCmd(argc, argv);

	std::string strAnswer;

	int n = 0;
	std::string j = ans.readString();

	if (j != "" || !ans.eof()) {
		strAnswer = j;
		std::string p = ouf.readString();
		if (j != p)
			quitf(_wa, "lines differ - expected: '%s' (len:%d, bytes:%s), found: '%s' (len:%d, bytes:%s)",
				compress(j).c_str(), j.size(), compress(escape(j)).c_str(),
				compress(p).c_str(), p.size(), compress(escape(p)).c_str());
	}

	quitf(_ok, "single line: '%s'", compress(strAnswer).c_str());
}

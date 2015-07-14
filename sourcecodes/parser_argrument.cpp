#include <itpp/itbase.h>
using namespace itpp;
using namespace std;
std::string PARSER_TEST_FILE = "parser_test_data.txt";
int main(int argc, char *argv[])
{
	Parser p;
	int a;
	double b;
	string c;
	ivec d;
	vec e;
	svec f;
	bvec g;
	imat h;
	mat i;
	smat j;
	bmat k;
	bool l, m;
	string n;
	Array<Array<cvec> > o, q;
	cout << "Use the Parser class on a parameter file:" << boolalpha << endl;
	p.init(string(PARSER_TEST_FILE));
	a = p.get_int("a");
	cout << "a = " << a << endl;
	p.get_double("b"); //The default value of b
	p.get_double("b", 1); //The first alternative value of b
	p.get_double("b", 2); //The second alternative value of b
	c = p.get_string("c");
	cout << "c = " << c << endl;
	d = p.get_ivec("d");
	cout << "d = " << d << endl;
	e = p.get_vec("e");
	cout << "e = " << e << endl;
	f = p.get_svec("f");
	cout << "f = " << f << endl;
	g = p.get_bvec("g");
	cout << "g = " << g << endl;
	h = p.get_imat("h");
	cout << "h = " << h << endl;
	i = p.get_mat("i");
	cout << "i = " << i << endl;
	j = p.get_smat("j");
	cout << "j = " << j << endl;
	k = p.get_bmat("k");
	cout << "k = " << k << endl;
	l = p.get_bool("l");
	cout << "l = " << l << endl;
	m = p.get_bool("m");
	cout << "m = " << m << endl;
	n = p.get_string("n");
	cout << "n = " << n << endl;
	cout << "------------------------------------------------------------"
			<< endl;
	cout << "Use the Parser class on the command line input:" << endl;
	cout << "Example: > ./parser_test.run \"a=3; b=-1.2; d=[0 1 2 45];\""
			<< endl << endl;
	cout << "Use the following code:" << endl;
	cout << " p.init(argc,argv);" << endl;
	cout << " a = p.get_int(\"a\"); cout << \"a = \" << a << endl;" << endl;
	cout << " b = p.get_double(\"b\"); cout << \"b = \" << b << endl;" << endl;
	cout << " d = p.get_ivec(\"d\"); cout << \"d = \" << d << endl;" << endl;
	cout << "------------------------------------------------------------"
			<< endl;
	cout
			<< "Use the Parser class on a char pointer (usually the command line input):"
			<< endl;
	char argv1_0[] = "a=345";
	char argv1_1[] = "b=1.001";
	char argv1_2[] = "c=\"Hello Bird\"";
	char argv1_3[] = "d=[1,2,3,-1,-2,-3]";
	int argc1 = 4;
	char *argv1[4] =
	{ argv1_0, argv1_1, argv1_2, argv1_3 };
	p.init(argc1, argv1);
	a = p.get_int("a");
	b = p.get_double("b");
	c = p.get_string("c");
	d = p.get_ivec("d");
	cout << "------------------------------------------------------------"
			<< endl;
	cout << "Use the Parser class on a parameter file and a char pointer:"
			<< endl;
// The data in the char pointer are selected first. The data in the
// file are used as default values
	char argv2_0[] = "a=345";
	char argv2_1[] = "d=[1,-2,3,-4,5,-6,7,-8]";
	int argc2 = 2;
	char *argv2[2] =
	{ argv2_0, argv2_1 };
	if (argc == 0)
	{
		p.init(string(PARSER_TEST_FILE), argc2, argv2);
	}
	else
	{
		p.init(string(PARSER_TEST_FILE), argc, argv);
	}
	a = p.get_int("a");
	cout << "a = " << a << endl;
	b = p.get_double("b");
	cout << "b = " << b << endl;
	c = p.get_string("c");
	cout << "c = " << c << endl;
	d = p.get_ivec("d");
	cout << "d = " << d << endl;
	cout << "------------------------------------------------------------"
			<< endl;
	cout << "Use the Parser class on an Array of strings:" << endl;
	Array<string> parser_data(4);
	parser_data(0) = "a=-11";
	parser_data(1) = "b=3.14";
	parser_data(2) = "c=\"Hello Nerd\"";
	parser_data(3) = "d=[0,1,2,0,3,4,7]";
	p.init(parser_data);
	a = p.get_int("a");
	b = p.get_double("b");
	c = p.get_string("c");
	d = p.get_ivec("d");
	cout << "------------------------------------------------------------"
			<< endl;
	cout << "Use the Parser::get() method on a parameter file:" << endl;
	p.init(string(PARSER_TEST_FILE));
	p.get(a, "a");
	p.get(b, "b");
	p.get(b, "b", 1);
	p.get(b, "b", 2);
	p.get(c, "c");
	p.get(d, "d");
	p.get(e, "e");
	p.get(f, "f");
	p.get(g, "g");
	p.get(h, "h");
	p.get(i, "i");
	p.get(j, "j");
	p.get(k, "k");
	p.get(l, "l");
	p.get(m, "m");
	p.get(n, "n");
	p.get(o, "o");
// The following tries can not be found in the data file, so their initial
// values should not be changed:
	set_array(q, "{{[1][2 3][4 5 6]}}");
	p.get(q, "q");
	bool r = true;
	p.get(r, "r");
	int s = 7;
	p.get(s, "s");
	double t = 3.14;
	p.get(t, "t");
	std::string u = "test string";
	p.get(u, "u");
	cout << "------------------------------------------------------------"
			<< endl;
	cout << "Check if variables exist in the Parser:" << endl;
	cout << "p.exist(\"a\") = " << p.exist("a") << endl;
	cout << "p.exist(\"aa\") = " << p.exist("aa") << endl;
	cout << "------------------------------------------------------------"
			<< endl;
	return 0;
}


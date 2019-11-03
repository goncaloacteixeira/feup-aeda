#ifndef SRC_EXCEPTIONS_H_
#define SRC_EXCEPTIONS_H_

#include <string>
using namespace std;

class FilaVazia {
	string msg;
public:
	FilaVazia() {msg = "Fila Vazia";}
	string getMsg() const {return msg;}
};


#endif /* SRC_EXCEPTIONS_H_ */

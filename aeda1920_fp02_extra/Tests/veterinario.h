#ifndef SRC_VETERINARIO_H_
#define SRC_VETERINARIO_H_

#include <string>
using namespace std;

/**
 * @brief Classe Veterinario
 *
 * Estrutura para armazenar informações basicas de um veterinário
 */

class Veterinario {
	string nome;    /**< nome do veterinário*/
	long codOrdem;  /**< código do veterinário*/
public:
    /** @brief Construtor da classe Veterinario
     *
     * @param nome nome do veterinário
     * @param cod  código do veterinário
     */
	Veterinario(string nome, int cod);

	/** @brief Método GET
	 *
	 * @returns nome do veterinário em questão
	 */
	string getNome() const;

    /** @brief Método GET
 *
 * @returns código do veterinário em questão
 */
    long getCod() const;
};


#endif /* SRC_VETERINARIO_H_ */

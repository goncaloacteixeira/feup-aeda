
#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;

/**
 * @brief Super-Classe Animal
 *
 * Estrutura para armazenar informações basicas de animais
 */

class Animal {
protected:
	string nome;            /**< nome do animal*/
	int idade;              /**< idadde do animal*/
	Veterinario *vet;       /**< veterinário do animal*/
	static int maisJovem;   /**< idade do animal mais novo*/
public:
    /** @brief Construtor da classe Animal
     *
     * @param nome nome do animal
     * @param idade idade do animal
     */
	Animal(string nome, int idade);

	/** @brief Método 'static' GET
	 *
	 * @returns idade do animal mais jovem
	 */
	static int getMaisJovem();

	/** @brief Método para determinar se o animal é jovem
	 *
	 * Um cão é jovem se tiver menos de 5 anos\n
	 * Um morcego é jovem se tiver menos de 4 anos
	 *
	 * @return true o animal é jovem
	 * @return false o animal não é jovem
	 */
	virtual bool eJovem();

	/** @brief Método SET
	 *
	 * Define o veterinário do animal em questão
	 *
	 * @param vet apontador para o veterninário que será atribuido ao animal em questão
	 */
	void setVet(Veterinario *vet);

	/** @brief Método GET
	 *
	 * @returns veterinário atribuido ao animal em questão
	 */
	Veterinario getVet();

	/**@brief Método GET
	 *
	 * @returns idade do animal em questão
	 */
	int getIdade();


	// virtual ~Animal(){};

	/** @brief Método GET
	 *
	 * @returns o nome do animal em questão
	 */
	string getNome() const;
	/** @brief Informações dos Animais
	 *
	 * @returns informações relativas ao animal em questão
	 */
	virtual string getInformacao();
};


/**
 * @brief Classe Derivada Cao
 *
 * Estrutura para armazenar informações de um Cão
 */
class Cao: public Animal {
	string raca;    /**< raça do animal*/
public:
    /** @brief Construtor da classe derivada Cao
     *
     * @param nome nome do cão
     * @param idade idade do cão
     * @param raca raça do cão
     */
	Cao(string nome, int idade, string raca);
	bool eJovem();
    string getInformacao();
};

/**
 * @brief Classe Voador
 *
 * Estrutura para armazenar informações de um Animal Voador
 */
class Voador {
	int velocidade_max;     /**< velocidade máxima do animal voador*/
	int altura_max;         /**< altura máxima do animal voador*/
public:
    /** @brief Construtor da classe Voador
     *
     * @param vmax velocidade máxima do animal voador
     * @param amax altura máxima do animal voador
     */
	Voador(int vmax, int amax);

	/** @brief Método GET
	 *
	 * @returns a velocidade maxima do animal voador
	 */
	int getVmax();

    /** @brief Método GET
    *
    * @returns a altura maxima do animal voador
    */
	int getAmax();
    // virtual ~Voador(){};
};

/**
 * @brief Classe Derivada Morcego
 *
 * Estrutura para armazenar informações de um Morcego
 */
class Morcego: public Animal, public Voador {
public:
    /** @brief Construtor da classe derivada de Animal e Voador
     *
     * @param nome nome do morcego
     * @param idade idade do morcego
     * @param vmax velocidade máxima do morcego
     * @param amax altura máxima do morcego
     */
	Morcego(string nome, int idade, int vmax, int amax);
    bool eJovem();
    string getInformacao();
};


#endif /* SRC_ANIMAL_H_ */

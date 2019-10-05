#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>
#include "veterinario.h"

/**
 * @brief Classe Zoo
 *
 * Estrutura para armazenar informações de um Zoo
 */

class Zoo {
	vector<Animal *> animais;               /**< vetor de apontadores de Animal que contem todos os animais do zoo*/
	vector<Veterinario *> veterinarios;     /**< vetor de apontadores de Veterinario que contem todos os veterinários do zoo*/
public:
    /** @brief construtor da classe Zoo
     *
     * a classe é definida com os vetores de veterinarios e animais sem elementos
     */
    Zoo();

    /** @brief Adiciona um animal ao vetor <animais>
     *
     * @see Animal
     *
     * @param a1 apontador para um animal
     */
    void adicionaAnimal(Animal *a1);

    /** @brief Numbero de animais no Zoo
     *
     * @returns tamanho do vetor <animais>
     */
	int numAnimais() const;

    /** @brief Numbero de veterinários no Zoo
     *
     * @returns tamanho do vetor <veterinarios>
     */
	int numVeterinarios() const;

	/** @brief Método GET
	 *
	 * @see Animal::getInformacao()
	 *
	 * @return informação relativa a todos os animais do Zoo
	 */
	string getInformacao();

	/** @brief Método para saber se um animal é jovem
	 *
	 * Procura o animal no vetor <animais>, se não o encontrar devolve o valor <false>
	 *
	 * @param nomeA nome do animal em questão
	 * @return false animal não é jovem
	 * @return true animal é jovem
	 */
	bool animalJovem(string nomeA);

	/** @brief Recolhe e distribui os veterinários disponiveis
	 *
	 * Armazena as informações dos veterinários existentes num ficheiro de texto organizado da seguinte forma:
	 *\n\n
	 * nome1\n
	 * cod1\n
	 * nome2\n
	 * cod2\n
	 *\n
	 * e de seguida chama a funçao atribuirVeterinarios()
	 *
	 * @sa atribuirVeterinarios()
	 *
	 * @param isV ifstream do ficheiro de veterinários
	 */
    void alocaVeterinarios(ifstream &isV);

    /** @brief Distribui os veterinários existentes pelos animais presentes no vetor <animais>
     *
     */
    void atribuirVeterinarios();

    /** @brief Remove o veterinario de nome nomeV do vetor veterinarios
     *
     * procura o veterinário que tenha como nome nomeV no vetor veterinários,
     * se existir, apaga-o do vetor. Se não existir, devolve valor false
     *
     * chama a função atribuirVeterinarios()
     *
     * @sa atribuirVeterinarios()
     *
     * @param nomeV nome do veterinário em questão
     * @return true se o veterinário for apagado com sucesso
     * @return false se o veterinário não existir
     */
    bool removeVeterinario(string nomeV);

    /** @brief Overload do operador '<'
     *
     * Um zoo é 'menor' que outro se a soma das idades dos seus animais for menor que a soma das idades dos animais do outro Zoo, 'zoo2'
     *
     * @return true Se a soma das idades dos seus animais for menor que a soma das idades dos animais do outro Zoo
     * @return false Se a soma das idades dos seus animais for maior ou igual que a soma das idades dos animais do outro Zoo
     */
    bool operator < (Zoo& zoo2) const;
};

#endif /* ZOO_H_ */

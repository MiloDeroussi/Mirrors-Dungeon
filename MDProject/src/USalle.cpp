#include "USalle.h"

USalle::USalle(std::string id, int nsalle, int nb_augment) : Salle(id,nsalle)
{
	this->nb_augment = nb_augment;
}

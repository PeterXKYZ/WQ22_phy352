#include <neural.h>

double energyFunction(IsingSpin* obj, IsingLattice2D* lptr)
{
    int x_size = lptr->xsize;
    int y_size = lptr->ysize;
    
    int ID = obj->ID;
    double obj_spin = obj->spin;
    double** jmat = lptr->Jmatrix;
    IsingSpin** spinarray = lptr->spinarray;
    
    double current_energy = 0;
    size_t k;

    for (size_t i = 0; i < y_size; ++i) {
        for (size_t j = 0; j < x_size; ++j) {
            k = i * x_size + j;
            current_energy += -jmat[ID][k] * obj_spin * spinarray[i][j].spin;
        }
    }

    obj->E = current_energy;

    // energy_difference = flipped_energy - current_energy,
    // but flipped_energy = -current_energy
    double energy_difference = -2 * current_energy;   

    return energy_difference;
}

void neuralFlip(IsingSpin* obj, IsingLattice2D* lattice)
{
    double energy_difference = energyFunction(obj, lattice);

    if (energy_difference <= 0) {
        obj->spin *= -1;
    }
}

double getTotalEnergy(IsingLattice2D* lattice)
{
    IsingSpin** spinarray = lattice->spinarray;

    double energy = 0;
    for (size_t i = 0; i < lattice->ysize; ++i) {
        for (size_t j = 0; j < lattice->xsize; ++j) {
            energy += spinarray[i][j].E;
        }
    }

    return energy;
}
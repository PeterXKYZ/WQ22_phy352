#include <magnetism.h>
#include <stdio.h>

double energyFunction(IsingSpin* obj, IsingLattice2D* lptr)
{
    double current_energy = -J * obj->spin * 
    (obj->above->spin + obj->right->spin + obj->below->spin + obj->left->spin);

    // If we add up all E in lattice, we would double count
    // the spin-interactions. Thus we must divide by 2.
    obj->E = .5 * current_energy;

    // energy_difference = flipped_energy - current_energy,
    // but flipped_energy = -current_energy
    double energy_difference = -2 * current_energy;   

    return energy_difference;
}

void boltzmannFlip(IsingSpin* obj, IsingLattice2D* lptr)
{
    double energy_difference = energyFunction(obj, lptr);
    
    if (energy_difference <= 0) {
        obj->spin *= -1;
        return;
    }
    
    double boltzmann_dist = exp(-energy_difference / (kB * lptr->T));
    double rval = (double) rand() * iRAND_MAX;

    if (rval - boltzmann_dist <= 0) {
        obj->spin *= -1;
    }
}

double getMagnetization(IsingLattice2D* lattice)
{
    
    IsingSpin* start_ptr = *(lattice->spinarray);
    IsingSpin* ptr = start_ptr;
    double magnetism = 0;

    while( ptr->next != start_ptr ) { 
        magnetism += ptr->spin;
        ptr = ptr->next;
    }
    magnetism += ptr->spin;

    return magnetism / (lattice->xsize * lattice->ysize);
}


double getEnergy(IsingLattice2D* lattice)
{
    IsingSpin* start_ptr = *(lattice->spinarray);
    IsingSpin* ptr = start_ptr;
    double energy = 0;

    while( ptr->next != start_ptr ) { 
        energy += ptr->E;
        ptr = ptr->next;
    }
    energy += ptr->E;

    return energy;
}



double getEnergyPerSpin(IsingLattice2D* lattice)
{
    
    IsingSpin* start_ptr = *(lattice->spinarray);
    IsingSpin* ptr = start_ptr;
    double energy_per_spin = 0;

    while( ptr->next != start_ptr ) { 
        energy_per_spin += ptr->E;
        ptr = ptr->next;
    }
    energy_per_spin += ptr->E;

    return energy_per_spin / (lattice->xsize * lattice->ysize);
}


double getEnergySquaredPerSpin(IsingLattice2D* lattice)
{
    
    IsingSpin* start_ptr = *(lattice->spinarray);
    IsingSpin* ptr = start_ptr;
    double energy_per_spin = 0;

    while( ptr->next != start_ptr ) { 
        energy_per_spin += ptr->E;
        ptr = ptr->next;
    }
    energy_per_spin += ptr->E;

    return energy_per_spin * energy_per_spin / (lattice->xsize * lattice->ysize);
}

//-----------------------------------------------------------------
void 
getCorrelationInfo(IsingLattice2D* lattice, CorrelationInfo* info ) 
//-----------------------------------------------------------------
{ 
    IsingSpin* start = *(lattice->spinarray);
    IsingSpin* ptr = start;

    for( size_t i = 0; i < lattice->xsize; ++i ) {
        info->spinsums[i] += ptr->spin;
        info->spinprodsums[i] += start->spin * ptr->spin;
        ptr = ptr->right;
    }

    ++(info->tests);
}


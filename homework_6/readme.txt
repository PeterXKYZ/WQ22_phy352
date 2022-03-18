Q1: Compared with the graph in lecture, it seems that
using a 100 x 100 grid reduces the noise around the
critical temperature by quite a lot. The transition 
temperature is still the same though.

Q2: For low temperature, since the entire lattice is
magnetized, every spin has an energy of -2. At around
the critical temperature, the energy per spin increases.
At high temperature, the energy per spin is creeping 
towards 0, but it is still negative. This means that
there are still large patches of "spin up" and that 
the lattice hasn't become random yet. 

Q3: For all lattice sizes, the specific heat peaks
at T = 2.3, which is our critcal temperature. For
larger lattice sizes, the peak is much sharper, with
a higher peak specific heat per spin. 

Q4: In the correlation plot, I fit the data using 
scipy curve_fit with model function y = a*exp(-x / l)
where a & l are the fitting parameters. l is the 
correlation length. The correlation length is highest
near critical temperature.

Q5: I produced snapshots of the lattice after
1000, 5000, 10000, and 50000 sweeps. They all look
fairly similar with small patches of "spin downs"
in midst of "spin ups". Most patches are small at 
around 2-3 pixels. This seems to agree with the 
correlation length of about 2 from the previous plot.

TECHNICAL COMMENTS:
-run Ising build script in Ising/
-run IsingPhysics build script IsingPhysics/
-run main build script in assignment directory
-run slurm scripts in assignment directory
-run "run" scripts in assignment directory.
    Note that for problem 2 & 3, the slurm 
    scripts produce the data, while the 
    run scripts are for testing.
-run python scripts in pyplot/
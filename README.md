🚀 C Projectile Simulator
This project is a high-performance Oblique Shot Simulator developed in pure C, featuring a custom terminal-based rendering engine.

🧠 Technical Details
Memory Management: Trajectory coordinates are stored using dynamic memory allocation (malloc), ensuring efficient heap usage based on the simulation's duration and time step.

Render Engine: A custom-built engine maps a 2D coordinate system onto a 1D linear memory buffer using advanced pointer arithmetic. This avoids the overhead of standard 2D arrays while maintaining pixel-perfect (character-perfect) accuracy.

Physics Engine: Parabolic trajectories are calculated using Euler integration, factoring in initial velocity vectors, launch angles, and gravitational acceleration.

Dynamic Scaling: The simulator automatically scales physical world coordinates (meters) to fit custom terminal dimensions (character cells) while preserving the aspect ratio of the flight path.

🚀 C Projectile Simulator
This project is a high-performance Oblique Shot Simulator developed in pure C, featuring a custom terminal-based rendering engine.

🧠 Technical Details
Memory Management: Trajectory coordinates are stored using dynamic memory allocation (malloc), ensuring efficient heap usage based on the simulation's duration and time step.

Render Engine: A custom-built engine maps a 2D coordinate system onto a 1D linear memory buffer using advanced pointer arithmetic. This avoids the overhead of standard 2D arrays while maintaining pixel-perfect (character-perfect) accuracy.

Physics Engine: Parabolic trajectories are calculated using Euler integration, factoring in initial velocity vectors, launch angles, and gravitational acceleration.

Dynamic Scaling: The simulator automatically scales physical world coordinates (meters) to fit custom terminal dimensions (character cells) while preserving the aspect ratio of the flight path.

📊 Output Example
The simulator visualizes the ball's trajectory from the initial launch height down to the ground level directly in the terminal. It features a dynamic Y-axis (vertical pole) representing the launch height and a horizontal X-axis representing the ground level.


// Example
Oblique Shot Simulation
Enter first cordinate-X: 0
Enter first cordinate-Y: 0
Enter first speed: 20
Enter shot degree: 30
Enter delta-time: 0.1
Enter gravity: 10
Enter screen-width: 100
Enter screen-height: 60

maxWidth: 34.641016, maxHeight: 5.000000, time: 2.000000

PosX: 0.000000 PosY: 0.000000 	 SpeedX: 17.320508 SpeedY: 10.000000 	 Time: 0.000000
PosX: 1.732051 PosY: 0.950000 	 SpeedX: 17.320508 SpeedY: 9.000000 	 Time: 0.100000
PosX: 3.464102 PosY: 1.800000 	 SpeedX: 17.320508 SpeedY: 8.000000 	 Time: 0.200000
PosX: 5.196152 PosY: 2.550000 	 SpeedX: 17.320508 SpeedY: 7.000000 	 Time: 0.300000
PosX: 6.928203 PosY: 3.200000 	 SpeedX: 17.320508 SpeedY: 6.000000 	 Time: 0.400000
PosX: 8.660254 PosY: 3.750000 	 SpeedX: 17.320508 SpeedY: 5.000000 	 Time: 0.500000
PosX: 10.392305 PosY: 4.200000 	 SpeedX: 17.320508 SpeedY: 4.000000 	 Time: 0.600000
PosX: 12.124356 PosY: 4.550000 	 SpeedX: 17.320508 SpeedY: 3.000000 	 Time: 0.700000
PosX: 13.856406 PosY: 4.800000 	 SpeedX: 17.320508 SpeedY: 2.000000 	 Time: 0.800000
PosX: 15.588457 PosY: 4.950000 	 SpeedX: 17.320508 SpeedY: 1.000000 	 Time: 0.900000
PosX: 17.320508 PosY: 5.000000 	 SpeedX: 17.320508 SpeedY: -0.000000 	 Time: 1.000000
PosX: 19.052559 PosY: 4.950000 	 SpeedX: 17.320508 SpeedY: -1.000000 	 Time: 1.100000
PosX: 20.784610 PosY: 4.800000 	 SpeedX: 17.320508 SpeedY: -2.000000 	 Time: 1.200000
PosX: 22.516660 PosY: 4.550000 	 SpeedX: 17.320508 SpeedY: -3.000000 	 Time: 1.300000
PosX: 24.248711 PosY: 4.200000 	 SpeedX: 17.320508 SpeedY: -4.000000 	 Time: 1.400000
PosX: 25.980762 PosY: 3.750000 	 SpeedX: 17.320508 SpeedY: -5.000000 	 Time: 1.500000
PosX: 27.712813 PosY: 3.200000 	 SpeedX: 17.320508 SpeedY: -6.000000 	 Time: 1.600000
PosX: 29.444864 PosY: 2.550000 	 SpeedX: 17.320508 SpeedY: -7.000000 	 Time: 1.700000
PosX: 31.176915 PosY: 1.800000 	 SpeedX: 17.320508 SpeedY: -8.000000 	 Time: 1.800000
PosX: 32.908965 PosY: 0.950000 	 SpeedX: 17.320508 SpeedY: -9.000000 	 Time: 1.900000
PosX: 34.641016 PosY: -0.000000 	 SpeedX: 17.320508 SpeedY: -10.000000 	 Time: 2.000000


                                             *    *    *                                            
                                        *                   *                                       
                                                                                                    
                                                                                                    
                                   *                             *                                  
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                              *                                       *                             
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                         *                                                 *                        
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                    *                                                           *                   
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
               *                                                                     *              
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
          *                                                                               *         
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
     *                                                                                         *    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
*--------------------------------------------------------------------------------------------------*
// Example

🛠️ Installation & Usage
1. Clone the repo:
git clone https://github.com/emircanozen122/C-Projectile-Simulator.git

2. Compile the source:
gcc oblique_shot_simulation.c -o simulator -lm

3. Run the simulation:
./simulator

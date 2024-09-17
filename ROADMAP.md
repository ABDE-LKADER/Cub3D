----------------------------------------
Cub3D Project Roadmap
----------------------------------------

1. Initial Setup
   - Understand Ray-Casting.
   - Install dependencies: MinilibX, math library.
   - Organize project structure: src/, include/, Makefile.

2. Map Parsing and Validation
   - Define the map format (0, 1, N, S, E, W).
   - Implement map parsing functions.
   - Validate the map for closed walls and correct formatting.

3. Ray-Casting Implementation
   - Set up player position and orientation based on the map.
   - Implement ray-casting for wall detection.
   - Draw walls based on ray distances.

4. Texture Mapping
   - Load wall textures for N/S/E/W.
   - Apply textures to the corresponding walls based on ray hits.

5. Player Movement and Rotation
   - Implement movement using W, A, S, D keys.
   - Implement rotation using left/right arrow keys.
   - Add collision detection to prevent walking through walls.

6. Rendering and Window Management
   - Set up window using MinilibX.
   - Render frames continuously in the game loop.
   - Handle exit conditions (ESC, red cross).

7. Testing and Error Handling
   - Test map parsing with edge cases.
   - Return proper error messages for invalid files.
   - Ensure proper memory management (no leaks).

8. Bonus Features (Optional)
   - Add wall collision detection.
   - Implement a minimap system.
   - Add doors that open and close.
   - Add animated sprites.
   - Implement mouse control for view rotation.

9. Final Steps
   - Polish the game and refine movement/visuals.
   - Clean up code and write documentation (README).
   - Thoroughly test on different maps.
   - Ensure compliance with project requirements.

----------------------------------------

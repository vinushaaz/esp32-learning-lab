ESP32 project workflow
Follow these steps in order for every new project.
1. Open VS Code
   
   Open Visual Studio Code.
2. Open your master repository
   
   File → Open Folder → Select esp32-learning-lab.
   
   Make sure you open the master folder, not an individual old project.
3. Pull the latest changes
   
   Open Source Control → Click ... → Pull.
   
   This downloads any new changes from GitHub before you start.
4. Create a new project folder
   
   Example:
   
   04-servo-motor was your previous project. Your next project should be:
   
   05-temperature-sensor
   
   Create it inside esp32-learning-lab.
5. Create the ESP-IDF project
   
   Use the ESP-IDF extension in VS Code to create your project inside the new folder.
6. Write your firmware
   
   Write code, configure components, understand the hardware and connections.
7. Build
   
   Click the Build button in VS Code.
   
   Fix errors until the build succeeds.
8. Flash and test
   
   Connect ESP32, flash firmware, open monitor and test the actual hardware.
9. Document your project
   
   Add a README.md containing:
   - Project objective
   - Components used
   - Wiring diagram
   - How it works
   - Results and photographs
10. Stage files
    
    Source Control → Click + beside Changes, or Stage All Changes.
11. Commit
    
    Write a meaningful message, for example:
    
    Add ESP32 temperature sensor project
    
    Click Commit.
12. Push
    
    Click Sync Changes or Push.
    
    Your new project is uploaded to your existing master GitHub repository!
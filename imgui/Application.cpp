#include "Application.h"
#include "Log.h"
#include "imgui/imgui.h"


namespace ClassGame {
        //
        // our global variables
        //

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        void GameStartUp() 
        {
                // just log errors here for now for testing
                Log::initialize(Log::Level::WARNING);        // start with WARNING threshold (console)
                Log::log(Log::Level::INFO,    "started logging");
                Log::log(Log::Level::WARNING, "memory allocated");
                Log::log(Log::Level::ERR,   "couldn't open file");
                Log::setConsoleLevel(Log::Level::INFO);
                Log::log(Log::Level::INFO,    "updated log level");
                Log::setConsoleLevel(Log::Level::ERR);
                Log::log(Log::Level::WARNING, "updated log level");

                //Log::shutdown();
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        void RenderGame() 
        {
            ImGui::DockSpaceOverViewport();
//            ImGui::ShowDemoWindow();

                static float f = 0.0f;
                static int counter = 0;
                bool show_demo_window = true;
                bool show_another_window = false;
                ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

                ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
                ImGui::Checkbox("Another Window", &show_another_window);

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                        counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
        }
}

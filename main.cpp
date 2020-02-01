#include <iostream>
#include "random.hpp"
#include "SFML/System.hpp"

// get base random alias which is auto seeded and has static API and internal state
using random = effolkronium::random_static;

int main(int argc, const char *argv[])
{
    int lower = 0;
    int higher = 0;
    int iterations = 0;
    int displayText = 1;
    int definedLineCount = 10;
    std::vector<int> storage;

    if (argc > 1) // if using cmd
    {
        if (argv[1] = "-")
        {
            lower = std::stoi(argv[2]);            // lower number to generate from
            higher = std::stoi(argv[3]);           // higher number to generate from
            iterations = std::stoi(argv[4]);       // number of times to iterate random generation
            displayText = std::stoi(argv[5]);      // toggles drawing random number on console (0 = off, 1 = on [default])
            definedLineCount = std::stoi(argv[6]); // amount of generated numbers to draw per console line
        }

        if (displayText == 1)
        {
            sf::Clock elapsedTime;
            int lineCount = -1;
            for (auto i = 0; i < iterations; i++)
            {
                auto num = random::get(lower, higher);
                storage.emplace_back(num);
                lineCount++;
                if (lineCount < definedLineCount)
                {
                    //printf("%i [%i] \t", num, i); // used for squashing a bug
                    printf("%i \t", num);
                }
                else
                {
                    //printf("\n%i [%i] \t", num, i);
                    printf("\n%i \t", num);
                    lineCount = 0;
                }
            }

            printf("\n\nTIME TAKEN : (MLS) %i\n", elapsedTime.getElapsedTime().asMilliseconds());
            printf("TIME TAKEN : (MCS) %i\n", elapsedTime.getElapsedTime().asMicroseconds());
        }
        else // no text
        {
            sf::Clock elapsedTime;
            for (auto i = 0; i < iterations; i++)
            {
                auto num = random::get(lower, higher);
                storage.emplace_back(num);
            }

            printf("\nTIME TAKEN : (MLS) %i\n", elapsedTime.getElapsedTime().asMilliseconds());
            printf("TIME TAKEN : (MCS) %i\n", elapsedTime.getElapsedTime().asMicroseconds());
        }
    }
    else // no cmd params
    {
        printf("enter lower bound [0] : ");
        std::cin >> lower;

        printf("enter higher bound [0] : ");
        std::cin >> higher;

        printf("enter iteration count [0] : ");
        std::cin >> iterations;

        printf("print generated numbers to screen? [0 : no] [1 : yes] : ");
        std::cin >> displayText;

        if (displayText == 1)
        {
            printf("how many numbers per line [10] : ");
            std::cin >> definedLineCount;
        }

        if (displayText == 1) // with text
        {
            sf::Clock elapsedTime;
            int lineCount = -1;
            for (auto i = 0; i < iterations; i++)
            {
                auto num = random::get(lower, higher);
                storage.emplace_back(num);

                lineCount++;
                if (lineCount < definedLineCount)
                {
                    //printf("%i [%i] \t", num, i);
                    printf("%i \t", num);
                }
                else
                {
                    //printf("\n%i [%i] \t", num, i);
                    printf("\n%i \t", num);
                    lineCount = 0;
                }
            }

            printf("\n\nTIME TAKEN : (MLS) %i\n", elapsedTime.getElapsedTime().asMilliseconds());
            printf("TIME TAKEN : (MCS) %i\n", elapsedTime.getElapsedTime().asMicroseconds());
        }
        else // no text
        {
            sf::Clock elapsedTime;
            for (auto i = 0; i < iterations; i++)
            {
                auto num = random::get(lower, higher);
                storage.emplace_back(num);
            }

            printf("\nTIME TAKEN : (MLS) %i\n", elapsedTime.getElapsedTime().asMilliseconds());
            printf("TIME TAKEN : (MCS) %i\n", elapsedTime.getElapsedTime().asMicroseconds());
        }
    }

    system("pause");
}

/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the necessary functions needed to
*               operate through a day at Zoo Tycoon. The majority of
*               actionable data is processed here and collected
*               from elsewhere throughout the program.
*********************************************************************/
#include "zoo.hpp"
#include <iostream>
#include <iomanip> // Required for several std::cout adjustments
#include <string> // Used in several instances when enum types are not used
#include <cstdlib> // Required for rand() functionality
#include <ctime> // Required for random seed used in program
#include <vector> // Used to make adjsutable containers

/********************************************************************* 
** Description: zoo::zoo()
*               Default zoo class constructor. Initializes all 
*               pertienent data members related to the zoo class.
*********************************************************************/
zoo::zoo()
{
    animalPopulation=3; // References Tiger, Penguin, and Turtle Enumerated data types
    day=0;
    srand(time(NULL)); // Used to create a random seed which the rand() function can use
    for (int i=0; i<animalPopulation; i++)  // The trackArray[] array is used to increment population counts 
        trackArray[i]=0;                    // across animal types
    for (int i=0; i<animalPopulation; i++)  // The arrayLength[] array tracks the individual array sizes for
        arrayLength[i]=10;                  // each animal type
    // Create dyanmic array which will hold tiger, penguin, and turtle animal classes
    cageArray = new animal*[3];
    cageArray[Tiger]=new tiger[arrayLength[Tiger]];
    cageArray[Penguin]=new penguin[arrayLength[Penguin]];
    cageArray[Turtle]=new turtle[arrayLength[Turtle]];
    bankBalance=100000; // Initial bank balance will be created by the program
}

/********************************************************************* 
** Description: void zoo::fillTheCage(AnimalType animalPurchased, zoo* newZoo)
*               Receives enumerated datatype AnimalType and a pointer to the
*               zoo class object. Utilizes both arguments to fill a
*               dynamic array with user requested or procedurally created
*               animals.
*********************************************************************/
void zoo::fillTheCage(AnimalType animalPurchased, zoo* newZoo)
{
    // Identify if animal in dynamic array location has been created yet
    if (cageArray[animalPurchased][trackArray[animalPurchased]].getAnimalNumber()==-1) 
    {
        // If not, incrememnt animal count for specific animal type
        cageArray[animalPurchased][trackArray[animalPurchased]].setAnimalNumber(trackArray[animalPurchased]); 
        // And set set age to 1 from -1
        cageArray[animalPurchased][trackArray[animalPurchased]].setAge(1);
        trackArray[animalPurchased]++;
    }
}

/********************************************************************* 
** Description: void zoo::statusPrint()
*               Implementing this function allows the user to visually
*               check the development of animal growth at the zoo.
*               It also lists pertinent information related to any
*               zoo animals created. 
*********************************************************************/
/*
void zoo::statusPrint()
{
    for (int i=0; i<animalPopulation; i++)
    {
        if (i==0)
            std::cout<< "Tiger:    #: ";
        else if (i==1)
            std::cout<< "Penguin:  #: ";
        else
            std::cout<< "Turtle:   #: ";

        for (int j=0; j<arrayLength[i]; j++)
        {
                std::cout << std::setw(2) << std::left << cageArray[i][j].getAnimalNumber() << " ";
        }
        std::cout<<std::endl;
        std::cout << "        Age: ";
        for (int j=0; j<arrayLength[i]; j++)
        {
                std::cout << std::setw(2) << std::left << cageArray[i][j].getAge() << " ";
        }
        std::cout<<std::endl;
        if (i==0)
            std::cout<< "Tiger array length is: " << arrayLength[i] << " and there are " << trackArray[i] << " tigers" << std::endl;
        else if (i==1)
            std::cout<< "Penguin array length is: " << arrayLength[i] << " and there are " << trackArray[i] << " penguins" << std::endl;
        else
            std::cout<< "Turtle array length is: " << arrayLength[i] << " and there are " << trackArray[i] << " turtles" << std::endl;
        std::cout<<std::endl;
    }
}
*/

/********************************************************************* 
** Description: void zoo::resizeArray(int animalArrayType)
*               When the default arrayLength is exceeded for any one 
*               type of animal this function resizes the dynamic
*               array. It does so by copying the original array to a 
*               placeholder, deleting the original array, then forming
*               a new dynamic array with the values stored in the 
*               placeholder.
*********************************************************************/
void zoo::resizeArray(int animalArrayType)
{
    // Create temporary array used to store original data
    animal* transferArray=NULL;
    // Double check that the array type (Tiger, Penguin, or Turtle) needs to expand
    if ((trackArray[animalArrayType]+1)>=(arrayLength[animalArrayType]))
        {
            // If it does need to expand create a new dynamic array with the properly allocated elements
            if (animalArrayType==Tiger)
                transferArray= new tiger[arrayLength[Tiger]+10];
            if (animalArrayType==Penguin)
                transferArray= new penguin[arrayLength[Penguin]+10];
            if (animalArrayType==Turtle)
                transferArray= new turtle[arrayLength[Turtle]+10];

            // Fill the temporary array with the values from the original array
            for (int j=0; j<arrayLength[animalArrayType]; j++)
            {
                transferArray[j]=cageArray[animalArrayType][j];
            }
            
            // Delete the old (and too small) original array
            delete [] cageArray[animalArrayType];

            // Increment the specific animal type array length by 10
            arrayLength[animalArrayType]+=10;

            // Create a new empty array at the same previous location with increased capacity
            if (animalArrayType==Tiger)
            cageArray[Tiger]= new tiger[arrayLength[Tiger]];
            if (animalArrayType==Penguin)
            cageArray[Penguin]= new penguin[arrayLength[Penguin]];
            if (animalArrayType==Turtle)
            cageArray[Turtle]= new turtle[arrayLength[Turtle]];
            
            // Copy the data from the temporary array into the new permanent array
            for (int j=0; j<arrayLength[animalArrayType]; j++)
            {
                cageArray[animalArrayType][j]=transferArray[j];
            }
            
            // Deallocate the temporary array
            delete [] transferArray;
        }
}

/********************************************************************* 
** Description: void zoo::increaseAge()
*               Iterates through each animal in the zoo and increments
*               age by 1 day.
*********************************************************************/
void zoo::increaseAge()
{
    for (int i=0; i<animalPopulation; i++)
    {
        for (int j=0; j<trackArray[i]; j++)
        {
            cageArray[i][j].advanceAge();
        }
    }
}

/********************************************************************* 
** Description: void zoo::calculateFeedCost()
*               Calculates the daily costs generated from each
*               animal in the zoo. Outputs results to consol.
*********************************************************************/
void zoo::calculateFeedCost()
{
    std::cout << std::endl << "Here are your food costs for day #" << getDay()+1 << ":" << std::endl << std::endl;
    int totalFoodCost=0, totalTigerCost=0, totalPenguinCost=0, totalTurtleCost=0;
    for (int i=0; i<animalPopulation; i++)
    {
        for (int j=0; j<trackArray[i]; j++)
        {
            // Catches tiger information only
            if (i==Tiger && cageArray[Tiger][j].getAge()>0)
                totalTigerCost+=cageArray[Tiger][j].getBaseFoodCost();
            // Catches penguin information only
            if (i==Penguin && cageArray[Penguin][j].getAge()>0)
                totalPenguinCost+=cageArray[Penguin][j].getBaseFoodCost();
            // Catches turtle information only
            if (i==Turtle && cageArray[Turtle][j].getAge()>0)
                totalTurtleCost+=cageArray[Turtle][j].getBaseFoodCost();
        }
    }
    totalFoodCost=totalTigerCost+totalPenguinCost+totalTurtleCost;
    std::cout << "      Tigers:   $" << std::setw(5) << std::right << totalTigerCost << std::endl;
    std::cout << "      Penguins: $" << std::setw(5) << std::right << totalPenguinCost << std::endl;
    std::cout << "      Turtles:  $" << std::setw(5) << std::right << totalTurtleCost << std::endl;
    std::cout << "                ------" << std::endl;
    std::cout << "      Total:    $" << std::setw(5) << std::right << totalFoodCost << std::endl << std::endl;
    
    std::cout << "      Previous balance:   $" << std::setw(9) << std::right << getBankbalance() << std::endl;
    std::cout << "      Food expense:       $" << std::setw(5) << std::right << "(" << totalFoodCost << ")" << std::endl;
    std::cout << "                          ----------" << std::endl;
    // Reflect changes in bank balance
    setBankbalance(getBankbalance()-totalFoodCost);
    std::cout << "      Remaining Balance:  $" << std::setw(9) << std::right << getBankbalance() << std::endl << std::endl;
}

/********************************************************************* 
** Description: double zoo::randomNumber()
*               Returns a double value to functions needing a randomized
*               result. 
*********************************************************************/
double zoo::randomNumber()
{
    // Return random value between 0 and 1
    return (double)rand()/(double)RAND_MAX;
}

/********************************************************************* 
** Description: void zoo::randomEvent()
*               Determines which random event will affect the player
*               during a round of gameplay and executes that event.
*               Seperated into 4 different events:
*                 1. An animal is born into the zoo (or given)
*                 2. An animal dies
*                 3. An uptick in customers occurs
*                 4. Nothing happens
*********************************************************************/
void zoo::randomEvent()
{
    int randVal, randAnimal, animalsLeft=3, tempStore, randAnimalLocation, sentinel=1;
    std::vector<int> parentsList(3);
    for (int i=0; i<animalPopulation; i++)
        parentsList[i]=i;
    randAnimal=randomNumber()*animalPopulation; // Used to select random animal that will either be born or die
    randVal=(randomNumber()*4); // Used to select random event in switch statement

    switch (randVal)
    {
        // Case 0: The zoo has an animal give birth, or the zoo must receive an animal from outside sources
        case 0:
        // While-loop used to iterate through included functions continuously until program determines that no animals
        // exist which can give birth.
        while (animalsLeft>0)
        {
            // trackArray array holds animal type population: eg. 2 tigers, 2 penguins, and 2 turtles. Prevents excessive looping
            for (int i=0; i<trackArray[randAnimal]; i++)
            {
                // Animals can only give birth if greater than or equal to 3 days old
                if (cageArray[randAnimal][i].getAge()>=3)
                {
                    std::cout << "Congratulations! One of your animals is now a proud parent!" <<std::endl;
                    // If the random animal type contains a member whose age is >= 3 days print notification to consol
                    if (randAnimal==Tiger)
                        std::cout << "     A Tiger has given birth to 1 new cub!" << std::endl << std::endl;
                    if (randAnimal==Penguin)
                        std::cout << "     A Penguin has hatched 5 new chicks!" << std::endl << std::endl;
                    if (randAnimal==Turtle)
                        std::cout << "     A Turtle has hatched 10 new babies!" << std::endl<< std::endl;
                    // Determine how many babies animal type will add to zoo population and loop through adding each new animal individually
                    for (int j=0; j<cageArray[randAnimal][i].getBabies(); j++)
                    {
                        // Check if animal type array will need to expand to fit new animal member
                        resizeArray(randAnimal);
                        // Add new animal 
                        cageArray[randAnimal][trackArray[randAnimal]].setAnimalNumber(trackArray[randAnimal]);
                        // Set age to 0 as it's a baby
                        cageArray[randAnimal][trackArray[randAnimal]].setAge(0);
                        // Increment anumal type population
                        trackArray[randAnimal]+=1;
                    }
                    // If animals were added through the above function, other functions below can identify what occured through the sentinel
                    sentinel=0;
                    // In order to break the while loop variable animalsLeft is set to 0
                    animalsLeft=0;
                    // No need to iterate through the for-loop again if a new set of animals was added
                    break;
                }
            }
            // If sentinel remains 1 at this point, the previous loops did not find an animal that could create babies under a specific animal type. The
            // below if-statement will change the random animal to one not yet selected and allow the program to iterate and try again
            if (sentinel)
            {                
                // Determine where the random animal type falls in a numeric vector, the vector is easier to mainpulate
                for (int i=0; i<animalsLeft; i++)
                {
                    if (parentsList[i]==randAnimal)
                        randAnimalLocation=i;
                }
                // Once location is found in the vector we will move it's value to the end of the vector
                tempStore=parentsList[animalsLeft-1];
                parentsList[animalsLeft-1]=parentsList[randAnimalLocation];
                // We do this by directly swapping it with the last value in the vector
                parentsList[randAnimalLocation]=tempStore;
                // Now we delete the last element in the vector so it can no longer be used again to find a random animal type
                parentsList.pop_back();
                // Decrementing animalsLeft in case we get to 0 and no suitable animal types exist
                animalsLeft--;
                // Repeat seacrch for random animal with adjusted animal type list 
                randAnimal=parentsList[randomNumber()*animalsLeft];
            }
        }
        // Final code that executes if sentinel remains at 1 and animalsLeft is reduced to 0.
        // That means no suitable animals exist to make babies in the whole zoo. Fortunately we can get help from an outside source
        if(sentinel)
        {
            std::cout << "Congratulations! Your zoo has been supplied with a new transfer!" <<std::endl;
            std::cout << "     You've been supplied with an adult ";
            if (randAnimal==Tiger)
                std::cout << "Tiger!" << std::endl << std::endl;
            if (randAnimal==Penguin)
                std::cout << "Penguin!" << std::endl << std::endl;
            if (randAnimal==Turtle)
                std::cout << "Turtle!" << std::endl << std::endl;
            resizeArray(randAnimal);
            cageArray[randAnimal][trackArray[randAnimal]].setAnimalNumber(trackArray[randAnimal]);
            cageArray[randAnimal][trackArray[randAnimal]].setAge(3);
            trackArray[randAnimal]+=1;
        }
        break;
        
        // Case 1: An animal has died and must be removed from existence in the dynamic array. Will be performed by returning animal
        // to default values.
        case 1:
        
        // Now we need to make sure that the game reacts to having no animals in an array when an animal dies
        for (int i=0; i<animalPopulation; i++)
        {
            // The if-function in this for-loop evaluates if there are any animals in the specific animal type array
            if (trackArray[randAnimal]<1)
            {
                // If not, we will look for an animal type that has animals in it
                for (int i=0; i<animalsLeft; i++)
                {
                    if (parentsList[i]==randAnimal)
                        randAnimalLocation=i;
                }
                // Once location is found in the vector we will move it's value to the end of the vector
                tempStore=parentsList[animalsLeft-1];
                parentsList[animalsLeft-1]=parentsList[randAnimalLocation];
                // We do this by directly swapping it with the last value in the vector
                parentsList[randAnimalLocation]=tempStore;
                // Now we delete the last element in the vector so it can no longer be used again to find a random animal type
                parentsList.pop_back();
                // Decrementing animalsLeft in case we get to 0 and no suitable animal types exist
                animalsLeft--;
                // Repeat seacrch for random animal with adjusted animal type list 
                randAnimal=parentsList[randomNumber()*animalsLeft];
            }
        }
        // If all three animal types are exhausted we default to case 3 of the switch statement, but include it here for brevity
        if (trackArray[randAnimal]<1)
        {
        std::cout << "Wow, today was a pretty uneventful day!" << std::endl;
        std::cout << "Nothing exceptional happened." << std::endl << std::endl;;
        break;  
        }
         
        std::cout << "A sad day at the zoo, an animal has passed away." << std::endl;
        // Determine which random animal was selected, and output respective death notice to consol
        if (randAnimal==Tiger)
            std::cout << "A single Tiger has moved on to greener pastures" << std::endl;
        if (randAnimal==Penguin)
            std::cout << "A single Penguin has moved on to greener pastures" << std::endl;
        if (randAnimal==Turtle)
            std::cout << "A single Turtle has moved on to greener pastures" << std::endl;

        // Decrement animal type population
        trackArray[randAnimal]--;
        // Set age to default
        cageArray[randAnimal][trackArray[randAnimal]].setAge(-1);
        // Set animal number to default
        cageArray[randAnimal][trackArray[randAnimal]].setAnimalNumber(-1);

        std::cout << "You now have " << trackArray[randAnimal] << " remaining" << std::endl << std::endl;
        break;
        
        // Case 2: Calculate bonus produced from a "busy" day, based on tigers in zoo
        case 2: 
        std::cout << "An unusually hectic day #" << getDay()+1 <<", and everyone wants to see the Tigers!" << std::endl << std::endl;
        int randomBonus;
        // Random bonus must lie somewhere between 250 and 500. Our random number function generates a value between 0 and 1
        randomBonus=(randomNumber()*250)+250;
        int totalBonus;
        totalBonus=randomBonus*trackArray[Tiger];
        
        std::cout << "      Bonus :      $" << std::setw(5) << std::right << randomBonus << std::endl;
        std::cout << "      # of Tigers: $" << std::setw(5) << std::right << trackArray[Tiger] << std::endl;
        std::cout << "                   --------" << std::endl;
        std::cout << "      Total:       $" << std::setw(5) << std::right << totalBonus << std::endl << std::endl;
        
        std::cout << "      Previous balance:   $" << std::setw(9) << std::right << getBankbalance() << std::endl;
        std::cout << "      Plus bonus:         $" << std::setw(9) << std::right << totalBonus << std::endl;
        std::cout << "                          ----------" << std::endl;
        setBankbalance(getBankbalance()+totalBonus);
        std::cout << "      Remaining Balance:  $" << std::setw(9) << std::right << getBankbalance() << std::endl << std::endl;
        break;
        
        // Case 3: A relaxing day!
        case 3:
        std::cout << "Wow, today was a pretty uneventful day!" << std::endl;
        std::cout << "Nothing exceptional happened." << std::endl << std::endl;;
        break;
    }
}

/********************************************************************* 
** Description: bool zoo::checkBalance()
*               Returns a value based on whether or not the player still
*               has enough funds to start a round
*********************************************************************/
bool zoo::checkBalance()
{
    // Now that the day's events are over let's determine if we need to start a new zoo due to profit loss
    if (getBankbalance()<0)
    {
        std::cout << "          It looks like you no longer have enough funds to run the zoo!" << std::endl;
        return 0;
    }
    return 1;
}

/********************************************************************* 
** Description: void zoo::calculatePayoff()
*               Calculates the daily profit generated from each
*               animal in the zoo. Does not include the addition of 
*               any bonuses. Outputs results to consol.
*********************************************************************/
void zoo::calculatePayoff()
{
    int totalProfit=0, tigerProfit=0, penguinProfit=0, turtleProfit=0;

    for (int i=0; i<animalPopulation; i++)
    {
        for (int j=0; j<trackArray[i]; j++)
        {
            // Catches tiger information only
            if (i==Tiger && cageArray[Tiger][j].getAge()>0)
                tigerProfit+=(cageArray[Tiger][j].getPayoff())*(cageArray[Tiger][j].getCost()); 
            // Catches penguin information only
            if (i==Penguin && cageArray[Penguin][j].getAge()>0)
                penguinProfit+=(cageArray[Penguin][j].getPayoff())*(cageArray[Penguin][j].getCost()); 
            // Catches turtle information only
            if (i==Turtle && cageArray[Turtle][j].getAge()>0)
                turtleProfit+=(cageArray[Turtle][j].getPayoff())*(cageArray[Turtle][j].getCost()); 
        }
    }
    
    std::cout << "Here are your zoo profts for day #" << getDay()+1 << std::endl << std::endl;
    
    totalProfit=tigerProfit+penguinProfit+turtleProfit;

    std::cout << "      Tigers:   $" << std::setw(5) << std::right << tigerProfit << std::endl;
    std::cout << "      Penguins: $" << std::setw(5) << std::right << penguinProfit << std::endl;
    std::cout << "      Turtles:  $" << std::setw(5) << std::right << turtleProfit << std::endl;
    std::cout << "                ------" << std::endl;
    std::cout << "      Total:    $" << std::setw(5) << std::right << totalProfit << std::endl << std::endl;
    
    std::cout << "      Previous balance:   $" << std::setw(9) << std::right << getBankbalance() << std::endl;
    std::cout << "      Zoo profits:        $" << std::setw(9) << std::right << totalProfit << std::endl;
    std::cout << "                          ----------" << std::endl;
    setBankbalance(getBankbalance()+totalProfit);
    std::cout << "      Remaining Balance:  $" << std::setw(9) << std::right << getBankbalance() << std::endl << std::endl;
}

/********************************************************************* 
** Description: Get and Set functions
*               Interface functions used to retrieve and change 
*               important zoo class data.
*********************************************************************/
int zoo::getDay()
{
    return day;
}

int zoo::getBankbalance()
{
    return bankBalance;
}

int zoo::getAnimalPopulation()
{
    return animalPopulation;
}

// Array length is directly related to a specific animal type, which requires the AnimalType argument
int zoo::getArrayLength(AnimalType animalGroup)
{
    return arrayLength[animalGroup];
}

void zoo::setDay(int newDay)
{
    day+=newDay;
}

void zoo::setBankbalance(int newBalance)
{
    bankBalance=newBalance;
}

void zoo::setAnimalPopulation(int newPopulation)
{
    animalPopulation=newPopulation;
}

void zoo::setArrayLength(AnimalType animalGroup, int newArrayLength)
{
    arrayLength[animalGroup]=newArrayLength;
}

/********************************************************************* 
** Description: zoo::~zoo()
*               zoo class destructor. Includes delete process of
*               cageArray member variable eliminating dynamically
*               allocated arrays in the program.
*********************************************************************/
zoo::~zoo()
{
    for (int i=0; i<animalPopulation; i++)
    {
        delete [] cageArray[i];
    }
    delete [] cageArray;
    cageArray=NULL;
}
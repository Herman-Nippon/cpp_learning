#include <iostream>

double fetchHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    return height;
}

double calculateFallenDist(int d_time, double gravity)
{
    return gravity * d_time / 2.0;
}

void print(int time, double dist, double height)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << height - dist << '\n';
}

int main()
{
    double height{ fetchHeight() };
    const double gravity{9.8};
    double fallen_distance{};

    for (int time = 0; time <= 5; time++){
        fallen_distance = calculateFallenDist(time * time, gravity);
        if (fallen_distance >= height){
            std::cout << "At " << time << " seconds, the ball is on the ground.\n";
            return 0;
        }
        print(time, fallen_distance, height);
    }

    return 0;
}

#include "../header/gymmanagementsystem.h"
#include <stdexcept>

using namespace Coruh::GymManagementSystem;

double GymManagementSystem::add(double a, double b) {
    return a + b;
}

double GymManagementSystem::subtract(double a, double b) {
    return a - b;
}

double GymManagementSystem::multiply(double a, double b) {
    return a * b;
}

double GymManagementSystem::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}
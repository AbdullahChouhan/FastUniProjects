#include <iostream>
#include <string>
#include <vector>

class Ingredient {
private:
    std::string name;
    double quantity;
    std::string unit;

public:
    Ingredient(const std::string& name, double quantity, const std::string& unit = "")
        : name(name), quantity(quantity), unit(unit) {}

    Ingredient(const Ingredient& obj) : name(obj.name), quantity(obj.quantity), unit(obj.unit) {}

    void setName(const std::string& name) {
        this->name = name;
    }

    void setQuantity(double quantity) {
        this->quantity = quantity;
    }

    void setUnit(const std::string& unit) {
        this->unit = unit;
    }

    std::string getName() const {
        return name;
    }

    double getQuantity() const {
        return quantity;
    }

    std::string getUnit() const {
        return unit;
    }

    void display() const {
        std::cout << name << " " << quantity << " " << unit << "\n";
    }
};

class Instruction {
private:
    int step;
    std::string text;

public:
    Instruction(int step, const std::string& text) : step(step), text(text) {}

    Instruction(const Instruction& obj) : step(obj.step), text(obj.text) {}

    void setStep(int step) {
        this->step = step;
    }

    void setText(const std::string& text) {
        this->text = text;
    }

    int getStep() const {
        return step;
    }

    std::string getText() const {
        return text;
    }

    void display() const {
        std::cout << step << ". " << text << "\n";
    }
};

class Recipe {
private:
    std::string name;
    std::string description;
    std::vector<Ingredient> ingredients;
    std::vector<Instruction> instructions;

public:
    Recipe(const std::string& name, const std::string& description = "") : name(name), description(description) {}

    Recipe(const Recipe& obj) : name(obj.name), description(obj.description), ingredients(obj.ingredients), instructions(obj.instructions) {}

    void setName(const std::string& name) {
        this->name = name;
    }

    void setDescription(const std::string& description) {
        this->description = description;
    }

    void setIngredients(const std::vector<Ingredient>& ingredients) {
        this->ingredients = ingredients;
    }

    void setInstructions(const std::vector<Instruction>& instructions) {
        this->instructions = instructions;
    }

    void addIngredient(const Ingredient& ingredient) {
        for (auto& i : ingredients) {
            if (i.getName() == ingredient.getName()) {
                std::cout << "Ingredient already exists.\n";
                return;
            }
        }
        ingredients.emplace_back(ingredient);
    }

    void addIngredient() {
        std::string name;
        double quantity;
        std::string unit;
        std::cout << "Enter the name of the ingredient: ";
        std::cin >> name;
        std::cout << "Enter the quantity of the ingredient: ";
        std::cin >> quantity;
        std::cout << "Enter the unit of the ingredient: ";
        std::cin >> unit;
        for (auto& i : ingredients) {
            if (i.getName() == name) {
                std::cout << "Ingredient already exists.\n";
                return;
            }
        }
        ingredients.emplace_back(Ingredient(name, quantity, unit));
    }

    void addInstruction() {
        int step;
        std::string text;
        std::cout << "Enter the step: ";
        std::cin >> step;
        std::cout << "Enter the text: ";
        std::cin.ignore();
        std::getline(std::cin, text);
        for (auto& i : instructions) {
            if (i.getText() == text) {
                std::cout << "Instruction already exists.\n";
                return;
            }
        }
        instructions.emplace_back(Instruction(step, text));
    }

    void addInstruction(const Instruction& instruction) {
        for (auto& i : instructions) {
            if (i.getText() == instruction.getText()) {
                std::cout << "Instruction already exists.\n";
                return;
            }
        }
        instructions.emplace_back(instruction);
    }

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    std::vector<Ingredient> getIngredients() const {
        return ingredients;
    }

    std::vector<Instruction> getInstructions() const {
        return instructions;
    }

    void display() const {
        std::cout << name << "\n";
        if (!description.empty()) {
            std::cout << description << "\n";
        }
        std::cout << "Ingredients:\n";
        for (const auto& i : ingredients) {
            i.display();
        }
        std::cout << "Instructions:\n";
        for (const auto& i : instructions) {
            i.display();
        }
    }
};

int main() {
    Recipe CAKE("Cake", "Layered cake");
    CAKE.addIngredient(Ingredient("Flour", 500, "g"));
    CAKE.addIngredient(Ingredient("Sugar", 100, "g"));
    CAKE.addIngredient(Ingredient("Eggs", 2, ""));
    CAKE.addInstruction(Instruction(1, "Preheat the oven to 180°C."));
    CAKE.addInstruction(Instruction(2, "Mix the ingredients."));
    CAKE.addInstruction(Instruction(3, "Bake for 20 minutes."));
    CAKE.display();

    return 0;
}
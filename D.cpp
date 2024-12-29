//"High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces). Abstractions should not depend on details. Details should depend on abstractions."

//Example of Violation of DIP
#include <iostream>
using namespace std;

class FileManager {
public:
    void saveToFile(const string& data) {
        cout << "Saving data to a file: " << data << endl;
    }
};

class ReportGenerator {
private:
    FileManager fileManager;  // High-level module directly depends on low-level module (FileManager)
public:
    void generateReport() {
        string data = "Report Data";
        fileManager.saveToFile(data);  // Tight coupling
    }
};

int main() {
    ReportGenerator report;
    report.generateReport();
    return 0;
}


// Problem:
// The ReportGenerator class (high-level module) directly depends on the FileManager class (low-level module). This is a violation of the Dependency Inversion Principle.
// If we want to change how data is saved (for example, save it to a database instead of a file), we will need to modify the ReportGenerator class, which violates the principle of low coupling.
// Solution (Applying DIP):
// Now, let's apply the Dependency Inversion Principle by introducing an interface. The high-level module (ReportGenerator) will depend on an abstraction (IDataSaver interface), and the low-level module (FileManager) will implement this interface.

#include <iostream>
using namespace std;

// Abstraction for saving data (Interface)
class IDataSaver {
public:
    virtual void saveData(const string& data) = 0;
};

// Low-level module (FileManager) implements IDataSaver
class FileManager : public IDataSaver {
public:
    void saveData(const string& data) override {
        cout << "Saving data to a file: " << data << endl;
    }
};

// Another low-level module (DatabaseManager) implements IDataSaver
class DatabaseManager : public IDataSaver {
public:
    void saveData(const string& data) override {
        cout << "Saving data to a database: " << data << endl;
    }
};

// High-level module (ReportGenerator) depends on abstraction (IDataSaver)
class ReportGenerator {
private:
    IDataSaver* dataSaver;  // High-level module depends on abstraction
public:
    ReportGenerator(IDataSaver* saver){
        dataSaver = saver;
    }

    void generateReport() {
        string data = "Report Data";
        dataSaver->saveData(data);  // No direct dependency on FileManager or DatabaseManager
    }
};

int main() {
    // Use FileManager to save data
    FileManager fileManager;
    ReportGenerator reportWithFile(&fileManager);
    reportWithFile.generateReport();

    // Use DatabaseManager to save data
    DatabaseManager dbManager;
    ReportGenerator reportWithDb(&dbManager);
    reportWithDb.generateReport();

    return 0;
}


// Explanation:
// IDataSaver Interface: This is an abstraction that defines the saveData() method. Both FileManager and DatabaseManager will implement this interface.
// FileManager and DatabaseManager: These are low-level modules that implement the IDataSaver interface. They handle how data is saved (file system or database).
// ReportGenerator: This is a high-level module that depends on the IDataSaver abstraction, not on the specific FileManager or DatabaseManager. It uses IDataSaver to save the data without worrying about the implementation.
// Benefits of Using DIP:
// Decoupling: The high-level module (ReportGenerator) doesn't depend on the low-level module (FileManager or DatabaseManager). It depends on the abstraction (IDataSaver), which makes it more flexible.
// Easier to Extend: If we need to add another way to save data (e.g., to a cloud service), we can create a new class that implements IDataSaver, without modifying the ReportGenerator class.
// Easier Maintenance: We can change the implementation of data saving (e.g., switch from file-based saving to database-based saving) without touching the high-level modules that use it.
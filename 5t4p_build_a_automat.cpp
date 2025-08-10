#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

struct AutomationScript {
    string scriptName;
    string triggerEvent;
    string actionCommand;
};

map<string, AutomationScript> automationScripts;

void addScript(string scriptName, string triggerEvent, string actionCommand) {
    AutomationScript script;
    script.scriptName = scriptName;
    script.triggerEvent = triggerEvent;
    script.actionCommand = actionCommand;
    automationScripts[scriptName] = script;
}

string generateScript(AutomationScript script) {
    string scriptCode = "# Automat Script: " + script.scriptName + "\n";
    scriptCode += "trigger: " + script.triggerEvent + "\n";
    scriptCode += "action: " + script.actionCommand + "\n";
    return scriptCode;
}

int main() {
    addScript("script1", "mouse.click", "keyboard.type('Hello World!')");
    addScript("script2", "keyboard.press('Ctrl+C')", "clipboard.copy()");

    ofstream scriptFile("automat_scripts.txt");

    for (auto& script : automationScripts) {
        scriptFile << generateScript(script.second) << "\n";
    }

    scriptFile.close();

    cout << "Automation scripts generated successfully!" << endl;

    return 0;
}
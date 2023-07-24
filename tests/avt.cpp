#include <iostream>
#include <avt.h>
#include <string>

class TestExecutor{
public:
    static void execute_0(){        
        com = "Execute_0";
    }
    static void execute_1(){        
        com = "Execute_1";
    }    
    static void execute_2(){        
        com = "Execute_2";
    }    
    static void execute_3(){        
        com = "Execute_3";
    }        
    static void execute_4(){        
        com = "Execute_4";
    }    
    static void execute_5(){        
        com = "Execute_5";
    }        
    static void execute_6(){        
        com = "Execute_6";
    }        
    static void execute_7(){        
        com = "Execute_7";
    }    
    static void execute_b(){        
        com = "Execute_b";
    }    
    static void execute_B(){        
        com = "Execute_B";
    }    
    static void execute_R(){        
        com = "Execute_R";
    }    
    static void execute_r(){        
        com = "Execute_r";
    }    
    static void execute_s(){        
        com = "Execute_s";
    }    
    static void execute_t(){        
        com = "Execute_t";
    }    
    static void execute_u(){        
        com = "Execute_u";
    }        
    static void execute_h(){        
        com = "Execute_h";
    }    
    static void execute_move(int mcount, int* mbuf){ 
        com = "Command 1 " + std::to_string(mcount);
        for(int i = 0; mbuf[i] != 0; i++)
            com += " " + std::to_string(mbuf[i]);
    }
    static void execute_scan(int scount, int* sbuf){
        com = "Command 3 " + std::to_string(scount);
        for(int i = 0; sbuf[i] != 0; i++)
            com += " " + std::to_string(sbuf[i]);
    }
    static void execute_waitTicks(int wcount){
        com = "Command 2 " + std::to_string(wcount);
    }
    static void execute_waitTime(int wtimecount){ 
        com = "Command 4 " + std::to_string(wtimecount);
    }
    static void error_unknownCommand(){
        com = "Unknown command";
    }
    static void error_nullAmount(){
        com = "Null amount";
    }
    static void error_undercount(){
        com = "Undercount command";
    }
    static void error_overflow(){
        com = "Overflow";
    }
    static void execute_setSpeed(int sscount){ 
        com = "Command 5 " + std::to_string(sscount);
    }

    static std::string com;
};

std::string TestExecutor::com = "";

int main(){
    ProtocoleAvt <TestExecutor> avtik;
    const static uint8_t mass[] = { 
        '$', 's', '3', '1', '1', '1', '2', '2', '#', //1. Unknown command
        '$', '3', '%', '1', '4', '2', 'a', '3', 'b', '9', '#', //2. Command 3 20 162 179 9
        '$', '2', '1', '2', '#', //3. Command 2 18
        '$', '2', '1', '2', '3', 'f', '3', 'k', '#', 'b', 'R', '4', '5', 'B', //4. Overflow, Ex_b, Ex_R, Ex_4, Ex_5, Ex_B
        '#', '0', '1', '2', //5. Ex_0, Ex_1, Ex_2,
        '#', '#', '#', '#', //Игнор
        '$', '#', '$', ' ', ' ', '#', //6. Unknown command, Unknown command
        '$', '3', '4', '#', '$', '6', '5', '#', //7. Undercount command, Unknown command
        '$', '3', '0', '1', '4', '2', 'a', '3', '#', //8. Undercount command
        '$', '2', '1', '#', //9. Undercount command
        '$', '3','0','1','0','2', 'a', '3', 'b','#', //10. Command 3 16 162 179
        '6', '7', 'r', 't', 's', 'u', 'h', //11. Ex_6, Ex_7, Ex_r, Ex_t, Ex_s, Ex_u, Ex_h
        '$', '4', '1', 'F', 's', '5', '#', //12. Command 4 7941
        '$', '5', 's', '1', 'f', 's', '5', '#', //13. Command 5 7941
        '$', '2', '1', '2', '3', //14. Overflow
        '$', '#', //15. Unknown command
        '$', '3', '0', '1', '5', '3', '3', '2', '3', 'f', 'r', '#', //16. Command 3 21 51 50 15
        '$', '1', ' ', ' ', '#', '$', '3', ' ', ' ', ' ', ' ', '#', //17. Overflow, Overflow
        '$', '2', ' ', ' ', '#', '$', '4', ' ', ' ', ' ', ' ', '#', //18. Null amount, Null amount
        '$', '5', ' ', ' ', ' ', ' ',' ', '#', //19. Null amount
        '$', '$', '$', //20. Unknown command, Unknown command, Unknown command
        '$', '3', '%', '1', '4', '2', 'a', '3', 'b', '9', '#', //21. Command 3 20 162 179 9
        '$', '2', 's', 's', '#', //22. Null amount
        '$', '2', 's', 's', 's', '1', '#', //23. Overflow
        '$', '4', 's', 's', 's', '1', '#', //24. Command 4 1
        '$', '5', 's', 's', 's', 'g', 'g', '#', '3', '3', //25. Null amount, Execute_3, Execute_3
        '$', '1', 's', 's', 's', '#', //26. Overflow
        '$', '1', 's', 's', 's', 'a', '#', //27. Overflow
        '$', '3', 's', 's', 's', 'd', '#', //28. Overflow
        '$', '1', 'D', 'a', 'k', '1', '0', '#', //29. Command 1 13 10 1
        '$', '1', '1', '4', '4', '#', //30. Overflow
        '$', '%', '3', '#', '3', //31. Unknown command, Execute_3
        '$', '2', '6', '6', '6', '#', //32. Overflow
        '$', ' ', '2', '#', 'j', 'l', '^', '@', 'm', //33. Unknown command
        '$', '1', '0', '0', '#', //34. Overflow
        '$', '1', '0', '#', //35. Null amount
        '$', '3', 'h', 'h', 'h', '#', //36. Null amount
        };

    int cntCom = 0;
    const std::string goodmass[] = {
        "Unknown command", //1
        "Command 3 20 162 179 9", //2 
        "Command 2 18", //3
        "Overflow", "Execute_b", "Execute_R", "Execute_4", "Execute_5", "Execute_B", //4
        "Execute_0", "Execute_1", "Execute_2", //5
        "Unknown command", "Unknown command", //6
        "Undercount command", "Unknown command", //7
        "Undercount command", //8
        "Undercount command", //9
        "Command 3 16 162 179", //10
        "Execute_6", "Execute_7", "Execute_r", "Execute_t", "Execute_s", "Execute_u", "Execute_h", //11
        "Command 4 7941", //12
        "Command 5 7941", //13
        "Overflow", //14
        "Unknown command", //15
        "Command 3 21 51 50 15", //16
        "Overflow", "Overflow", //17
        "Null amount", "Null amount", //18
        "Null amount",  //19
        "Unknown command", "Unknown command", "Unknown command", //20
        "Command 3 20 162 179 9", //21
        "Null amount", //22
        "Overflow", //23
        "Command 4 1", //24
        "Null amount", "Execute_3", "Execute_3", //25
        "Overflow", //26
        "Overflow", //27
        "Overflow", //28
        "Command 1 13 10 1", //29
        "Overflow", //30
        "Unknown command", "Execute_3", //31
        "Overflow", //32
        "Unknown command", //33
        "Overflow", //34
        "Null amount", //35
        "Null amount" //36
        };

    for (unsigned int i = 0; i < sizeof(mass); i++)
    {
        avtik.readByte(mass[i]);
        if(TestExecutor::com != ""){
            if(goodmass[cntCom] != TestExecutor::com){
                std::cout << "ERROR: expected " << goodmass[cntCom] 
                << " but received " << TestExecutor::com << std::endl;
                return 1;
           }
            cntCom++;
            TestExecutor::com = "";
        }
    }
    return 0;
}

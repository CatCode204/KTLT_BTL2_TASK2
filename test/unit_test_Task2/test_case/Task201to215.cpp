#include "../unit_test_Task2.hpp"

bool UNIT_TEST_Task2::Task204()
{
    string name = "Task204";
    //! data ------------------------------------
    // Sử dụng 2 Vehicle:
    // v1: TANK có getAttackScore() = 6*304 + (5*2) = 1824 + 10 = 1834 → clamp về 1000.
    // v2: MORTAR có getAttackScore() = 1*304 + (3*1) = 304 + 3 = 307.
    Vehicle v1(3, 1, Position(1,1), ANTIAIRCRAFT);
    Vehicle v2(5, 2, Position(1,2), MORTAR);
    // Sử dụng 3 Infantry với các loại khác nhau:
    // i1: SNIPER → score = 2.
    // i2: SPECIALFORCES → score = 3.
    // i3: REGULARINFANTRY → score = 4.
    Infantry i1(2, 1, Position(2,1), SNIPER);
    Infantry i2(3, 1, Position(2,2), SPECIALFORCES);
    Infantry i3(4, 1, Position(2,3), REGULARINFANTRY);
    
    // Tổng LF: v1 + v2 = (1834+307) > 1000 → LF = 1000.
    // Tổng EXP: 2 + 
    Unit** unitArray = new Unit*[5];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &i1;
    unitArray[3] = &i2;
    unitArray[4] = &i3;
    LiberationArmy* army = new LiberationArmy(unitArray, 5, "TestArmy207");

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());
    //! expect ----------------------------------
    string expect = "32\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task205()
{
    string name = "Task205";
    //! data ------------------------------------
    /* Vehicle */
    Vehicle v1(2, 1, Position(1,1), TRUCK);         
    Vehicle v2(3, 1, Position(1,2), MORTAR);          
    Vehicle v3(3, 2, Position(1,3), ARMOREDCAR);      
    Vehicle v4(4, 1, Position(1,4), TANK);             
    Vehicle v5(4, 2, Position(1,4), ARTILLERY);             
    Vehicle v6(1, 1, Position(1,4), ARTILLERY);            
    Vehicle v7(1, 2, Position(1,4), APC);             
    Vehicle v8(3, 4, Position(1,4), APC);     
    /* Infantry */        
    Infantry i1(10, 1, Position(2,1), SNIPER);            
    Infantry i2(20, 1, Position(2,2), SPECIALFORCES);      
    Infantry i3(15, 1, Position(2,3), ENGINEER);           
    Infantry i4(7, 1, Position(2,4), REGULARINFANTRY);     

    Unit** unitArray = new Unit*[12];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &v3;
    unitArray[3] = &v4;
    unitArray[4] = &v5;
    unitArray[5] = &v6;
    unitArray[6] = &v7;
    unitArray[7] = &v8;
    unitArray[8] = &i1;
    unitArray[9] = &i2;
    unitArray[10] = &i3;
    unitArray[11] = &i4;

    LiberationArmy* army = new LiberationArmy(unitArray, 12, "TestArmy205");

    //! process ---------------------------------
    string result = to_string(army->getLF()) + "\n" + to_string(army->getEXP());

    //! expect ----------------------------------
    string expect = "197\n333";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task206()
{
    string name = "Task206";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);
    
    Unit* unitArray[1];
    unitArray[0] = &v1;
    
    LiberationArmy army = LiberationArmy(unitArray, 1, "TestArmy206");
    Army* copy = &army;

    //! process ---------------------------------
    string result = army.str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[TestArmy206,LF=61,EXP=0,unitList=(UnitList[count_vehicle=3;count_infantry=0;"
        "Vehicle[vehicleType=TANK,quantity=3,weight=1,pos=(1,1)]])]";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    // delete army;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task207()
{
    string name = "Task207";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1,1), TANK);
    Vehicle v2(4, 2, Position(1,2), TRUCK);
    Vehicle v3(5, 2, Position(3,1), MORTAR);
    Vehicle v4(2, 3, Position(3,3), ARTILLERY);
    
    Infantry i1(2, 1, Position(2,1), SNIPER);
    Infantry i2(4, 2, Position(2,2), SPECIALFORCES);
    Infantry i3(3, 1, Position(3,2), SNIPER);
    
    Unit* unitArray[7];
    unitArray[0] = &v1;
    unitArray[1] = &v2;
    unitArray[2] = &i1;
    unitArray[3] = &i2;
    unitArray[4] = &v3;
    unitArray[5] = &i3;
    unitArray[6] = &v4;
    
    LiberationArmy* army = new LiberationArmy(unitArray, 7, "TestArmy207");

    //! process ---------------------------------
    string result = army->str();
    
    //! expect ----------------------------------
    string expect = "LiberationArmy[TestArmy207,LF=124,EXP=238,unitList=(UnitList[count_vehicle=14;count_infantry=9;"
    "Infantry[infantryType=SPECIALFORCES,quantity=4,weight=2,pos=(2,2)],"
    "Infantry[infantryType=SNIPER,quantity=5,weight=1,pos=(2,1)],"
    "Vehicle[vehicleType=TANK,quantity=3,weight=1,pos=(1,1)],"
    "Vehicle[vehicleType=TRUCK,quantity=4,weight=2,pos=(1,2)],"
    "Vehicle[vehicleType=MORTAR,quantity=5,weight=2,pos=(3,1)],"
    "Vehicle[vehicleType=ARTILLERY,quantity=2,weight=3,pos=(3,3)]])]";
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete army;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

// 1 1 2 3 5 8 13 21 34 55 89 144 233
bool UNIT_TEST_Task2::Task208()
{
    string name = "Task208";
    //! data ------------------------------------
    /* Defense = True, 0 satisfy */
    Vehicle v1(9, 1, Position(1,1), APC);                               // 41 -> 54
    Infantry i1(4, 4, Position(1,2), ANTIAIRCRAFTSQUAD);                // 72
    Infantry i2(1, 2, Position(1,3), MORTARSQUAD);                      // 114
    // Total EXP = 242
/*
    Update:
- LF:
1st:
    Quantity: 9     ->  13
2nd:
    Quantity: 13    ->  21
3rd:
    Quantity: 21    ->  34
4th:
    Quantity: 34    ->  55
    ==> LF = 43 
- EXP:
1st:
    Quantity i1: 4 -> 5 -> 6(cập nhập theo điều kiện) => 80
    Quantity i2: 1 -> 2 => 116
2nd:
    Quantity i1: 5 -> 8 => 88
    Quantity i2: 2 -> 3 => 118
3rd:
    Quantity i1: 8 -> 13 => 108
    Quantity i2: 3 -> 5 => 124
4th:
    Quantity i1: 13 -> 21 => 160
    Quantity i2: 5 -> 8 => 128
    ==> 374 
====> 1 of 2 satisfactory condition -> quantity lose 10%
====>
    Vehicle:
        55 -> 50 
        => 43
    Infantry:
        21 -> 19 -> 18: 128 (safeCeil)
        6 -> 8 -> 8: 128 (safeCeil)
        => 256
*/

    Unit* unitArray1[3];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy208");
    
    Vehicle v2(17, 3, Position(3,1), TANK);                     // 63
    Infantry i3(3, 5, Position(3,2), SNIPER);                   // 15
    Infantry i4(1, 1, Position(3,3), SPECIALFORCES);            // 300     
    // Total exp = 315 

    Unit* unitArray2[3];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    unitArray2[2] = &i4;
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy208");

    //! process ---------------------------------
    attacker->fight(enemy, true);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 43\nNew_EXP = 256";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task209()
{
    string name = "Task209";
    //! data ------------------------------------
    /* Defense = False */
    /* Testcase for 0 satisfactory -> fight does not exist */
    Vehicle v1(3, 10, Position(1,1), TRUCK);                   // 30 -> 45
    Infantry i1(4, 12, Position(1,2), SNIPER);                 // 48 -> 72

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy209");
    
    Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
    Infantry i3(3, 30, Position(3,2), SNIPER);                  // 90
    // LF = 62
    // EXP = 175

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy209");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    // Combat not exist -> weight - 10% -> update LF, EXP
    // 10 -> 9 => 27
    // 12 -> 11 => 44
    string expect = "New_LF = 1\nNew_EXP = 44";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task201()
{
    string name = "Task201";
    //! data ------------------------------------
    Vehicle tankOfLiber(5, 2, Position(1, 2), TANK);
    Vehicle truckOfLiber(3, 1, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(5, 2, Position(1, 1), SNIPER);

    Unit** unitArrayOfLiber = new Unit*[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;
    LiberationArmy* liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "TestArmy201");

    //! process ---------------------------------
    string result = to_string(liberationArmy->getLF()) + "\n" + to_string(liberationArmy->getEXP());

    //! expect ----------------------------------
    string expect = "63\n10"; 

    // cout << expect;
    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete liberationArmy;
    delete[] unitArrayOfLiber;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task202()
{
    string name = "Task202";
    //! data ------------------------------------
    Vehicle v1(3, 1, Position(1, 1), TANK);
    Infantry i1(2, 1, Position(1, 2), SNIPER);
    
    Unit** unitArray = new Unit*[2];
    unitArray[0] = &v1;
    unitArray[1] = &i1;
    LiberationArmy* army = new LiberationArmy(unitArray, 2, "TestArmy202");
    Army* copy = army;

    //! process ---------------------------------
    string result = to_string(copy->getLF()) + "\n" + to_string(copy->getEXP());

    //! expect ----------------------------------
    // Với v1, getAttackScore() = 1827 nhưng bị clamp về 1000; với i1, score = 2.
    string expect = "61\n2"; 

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete army;
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task203()
{
    string name = "Task203";
    //! data ------------------------------------
    // Tạo 3 đơn vị Infantry với tổng score ban đầu vượt quá 500.
    Infantry i1(300, 1, Position(1,1), SNIPER);          // score = 300 (theo giả định: score = quantity)
    Infantry i2(250, 1, Position(1,2), REGULARINFANTRY);   // score = 250
    Infantry i3(200, 1, Position(1,3), ENGINEER);          // score = 200
    // Tổng EXP = 300 + 250 + 200 = 750  → bị clamp về 500.
    Unit** unitArray = new Unit*[3];
    unitArray[0] = &i1;
    unitArray[1] = &i2;
    unitArray[2] = &i3;
    LiberationArmy army = LiberationArmy(unitArray, 3, "TestArmy206");
    Army* copy1 = &army;
    Army** copy2 = &copy1;

    //! process ---------------------------------
    string result = to_string((*copy2)->getLF()) + "\n" + to_string((*copy2)->getEXP());
    //! expect ----------------------------------
    // Không có Vehicle nên LF = 0; EXP bị clamp thành 500.
    string expect = "0\n500";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------
    delete[] unitArray;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task211()
{
    string name = "Task211";
    //! data ------------------------------------
    /* Defense = True, 2 satisfy */
    Vehicle v1(3, 1, Position(1,1), TANK);                     // 61 -> LF = 61 * 1.3 = 80
    Infantry i1(57, 4, Position(1,2), ENGINEER);               // 171 -> EXP = 171 * 1.3 = 396

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy211");
    
    Vehicle v2(3, 3, Position(3,1), TANK);                     // 62
    Infantry i2(62, 1, Position(3,2), REGULARINFANTRY);        // 342      

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy211");

    //! process ---------------------------------
    attacker->fight(enemy, true);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 61\nNew_EXP = 396";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task212()
{
    string name = "Task212";
    //! data ------------------------------------
    /* defense = False */
    /* Testcase for 1 satisfactory Combo A or B but still victory */
    Vehicle v1(3, 1, Position(1,1), TANK);                      // 61
    Infantry i1(4, 1, Position(1,2), SNIPER);                   // 5
    Infantry i2(3, 1, Position(1,3), SPECIALFORCES);            // 303
    // LF = 61 * 1.5 = 91.5
    // EXP = 307

    Unit* unitArray1[3];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 3, "TestArmy212");
    
    Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
    Infantry i3(2, 1, Position(3,2), SNIPER);                   // 2
    Infantry i4(2, 1, Position(3,3), ANTIAIRCRAFTSQUAD);        // 59
    Infantry i5(2, 1, Position(3,4), MORTARSQUAD);              // 114
    // LF = 62
    // EXP = 175

    Unit* unitArray2[4];
    unitArray2[0] = &v2;
    unitArray2[1] = &i3;
    unitArray2[2] = &i4;
    unitArray2[3] = &i5;
    Army* enemy = new ARVN(unitArray2, 4, "EnemyArmy212");
    
    //! process ---------------------------------
/*
Sau giao tranh:
    Infantry i1(4, 1, Position(1,2), SNIPER);                   // 5
    Infantry i3(2, 1, Position(3,2), SNIPER);                   // 2
    Infantry i4(2, 1, Position(3,3), ANTIAIRCRAFTSQUAD);        // 59
    Infantry i5(2, 1, Position(3,4), MORTARSQUAD);              // 114
    Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
*/
    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    string expect = "New_LF = 62\nNew_EXP = 181";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task213()
{
    string name = "Task213";
    //! data ------------------------------------
    /* defense = False */
    /* Testcase for 1 satisfactory Combo A or B but still victory */
    Vehicle v1(3, 1, Position(1,1), TANK);                      // 61
    Infantry i1(10, 1, Position(1,2), SNIPER);                  // 10

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy213");
    
    Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
    Infantry i2(3, 3, Position(3,2), SNIPER);                   // 9
    // LF = 62
    // EXP = 175

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy213");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());
/*
Sau giao tranh:
Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
Infantry i2(3, 3, Position(3,2), SNIPER);                   // 9
*/
    //! expect ----------------------------------
    string expect = "New_LF = 62\nNew_EXP = 9";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task214()
{
    string name = "Task214";
    //! data ------------------------------------
    /* defense = False */
    /* Testcase for 2 satisfactory Combo A and B -> Victory */
    Vehicle v1(2, 1, Position(1,1), TANK);                          // 61
    Vehicle v2(1, 1, Position(1,2), APC);                           // 41
    Infantry i1(3, 1, Position(2,1), ANTIAIRCRAFTSQUAD);            // 69
    Infantry i2(1, 1, Position(2,2), SPECIALFORCES);                
    // LF = 30
    // EXP = 50
    // -> Chọn v1 cho combo B
    // -> chọn i1 cho combo A
    Unit* unitArray1[4];
    unitArray1[0] = &v1;
    unitArray1[1] = &v2;
    unitArray1[2] = &i1;
    unitArray1[3] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy214");
    
    Vehicle v3(1, 1, Position(3,1), ARTILLERY);                     // 51
    Infantry i3(1, 1, Position(3,2), SNIPER);                       // 1
    // LF = 10
    // EXP = 10
    /* Unit lúc sau:
    Infantry i3(1, 1, Position(3,2), SNIPER);                       // 1
    Infantry i2(1, 1, Position(2,2), SPECIALFORCES);                
    Vehicle v3(1, 1, Position(3,1), ARTILLERY);                     // 51
    Vehicle v2(1, 1, Position(1,2), APC);                           // 41

    */

    Unit* unitArray2[2];
    unitArray2[0] = &v3;
    unitArray2[1] = &i3;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy214");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    // Tank with LF = 20 -> satisfy (20 > 10) -> New_LF = 30 - 20 + 10 = 20
    // EXP = 30 -> 50 - 30 + 10 = 30
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());
    
    //! expect ----------------------------------
    string expect = "New_LF = 92\nNew_EXP = 301";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task215()
{
    // cout << "TASK215" << endl;
    string name = "Task215";
    //! data ------------------------------------
    /* Defense = True, only 1 satisfies*/
    Vehicle v1(112, 4, Position(1,1), TANK);                    // 76 -> LF = 62 * 1.3 = 99
    Infantry i1(3, 1, Position(1,2), ENGINEER);                 // 171 -> EXP = 171 * 1.3 = 223

    Unit* unitArray1[2];
    unitArray1[0] = &v1;
    unitArray1[1] = &i1;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 2, "TestArmy215");
    
    Vehicle v2(3, 3, Position(3,1), TANK);                      // 62
    Infantry i2(3, 1, Position(3,2), REGULARINFANTRY);          // 284

    Unit* unitArray2[2];
    unitArray2[0] = &v2;
    unitArray2[1] = &i2;
    Army* enemy = new ARVN(unitArray2, 2, "EnemyArmy215");

    //! process ---------------------------------
    attacker->fight(enemy, true);
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());

    //! expect ----------------------------------
    // Quantity decrease 10%
    // 112 -> 101 => 75
    // 3 -> 2.7 ~ 3
    string expect = "New_LF = 75\nNew_EXP = 171";

    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Task2::Task210()
{
    string name = "Task210";
    //! data ------------------------------------
    /* defense = False */
    /* Testcase for 2 satisfactory Combo A and B -> Victory */
    Vehicle v1(3, 5, Position(1,1), TANK);                          // 62 
    Vehicle v2(1, 1, Position(1,2), APC);                           // 41
    Infantry i1(4, 1, Position(2,1), ANTIAIRCRAFTSQUAD);            // 60
    Infantry i2(3, 1, Position(2,2), SPECIALFORCES);                // 303
    // LF = 103
    // EXP = 363
// -> Chọn v1 cho combo B
// -> chọn i1 cho combo A
    Unit* unitArray1[4];
    unitArray1[0] = &v1;
    unitArray1[1] = &v2;
    unitArray1[3] = &i1;
    unitArray1[2] = &i2;
    LiberationArmy* attacker = new LiberationArmy(unitArray1, 4, "TestArmy210");
    
    Vehicle v3(3, 1, Position(3,1), ARTILLERY);                     // 51
    Vehicle v4(3, 2, Position(3,3), TRUCK);                         // 6
    Infantry i3(3, 2, Position(3,2), SNIPER);                       // 6
    // LF = 57
    // EXP = 6
/* Unit lúc sau:
Infantry i3(3, 2, Position(3,2), SNIPER);                       // 6
Infantry i2(3, 1, Position(2,2), SPECIALFORCES); 
Vehicle v3(3, 1, Position(3,1), ARTILLERY);                     // 51
Vehicle v4(3, 2, Position(3,3), TRUCK);                         // 6
Vehicle v2(1, 1, Position(1,2), APC);
*/

    Unit* unitArray2[3];
    unitArray2[0] = &v3;
    unitArray2[1] = &v4;
    unitArray2[2] = &i3;
    Army* enemy = new ARVN(unitArray2, 3, "EnemyArmy210");
    
    //! process ---------------------------------
    attacker->fight(enemy, false);
    // Tank with LF = 62 -> satisfy (62 > 57) -> New_LF = 103 - 62 + 57 = 98
    // EXP = 60 -> 363 - 60 + 6 = 309
    string result = "New_LF = " + to_string(attacker->getLF()) + "\nNew_EXP = " + to_string(attacker->getEXP());
    
    //! expect ----------------------------------
    string expect = "New_LF = 93\nNew_EXP = 309";
    
    //! output ----------------------------------
    stringstream output;
    output << result;
    
    //! remove data -----------------------------
    delete attacker;
    delete enemy;
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
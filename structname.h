#ifndef STRUCTNAME_H_INCLUDED
#define STRUCTNAME_H_INCLUDED


typedef struct Salary_information   //工资信息
{
    char person_ID[10];      //员工编号
    char person_name[25];    //员工姓名
    char date_salary[15];    //工资日期
    double basic_salary;     //基本工资
    double pos_salary;       //职位工资
    double kpi_salary;       //绩效工资
    double reward;           //奖罚
    double deserve_salary;   //应发工资
    double net_salary;       //实发工资
    double tax;              //扣税
    double insurance_fund;   //五险一金
    struct Salary_information *Salary_node;     //链表指针
};

typedef struct Change_information   //工作变动信息
{
    char person_ID[10];      //员工编号
    char person_name[25];    //员工姓名
    char date_change[15];    //变动时间
    char original_department[20];  //原部门
    char original_pos[50];         //原职位
    char fresh_department[20];     //新部门
    char fresh_pos[50];            //新职位
    struct Change_information *Change_node;           //链表指针
};

typedef struct Staff        //员工
{
    char person_ID[10];     //员工编号
    char person_name[25];   //员工姓名
    char ID_num[19];        //身份证号
    char join_date[15];     //入职时间
    char email_address[40];  //电子邮箱
    char phonenum[20];        //联系电话
    char home[200];          //员工家庭住址
    char university[50];     //毕业院校
    char degree[12];         //最终学历
    struct Salary_information *Salary_information_ptr;  //工资信息指针
    struct Change_information *Change_information_ptr;   //工作变动信息指针
    struct Pos *Pos_ptr;            //职位信息指针
    struct Staff *Staff_node;      //链表指针
};


typedef struct Pos       //职位
{
    char Pos_ID[10];      //职位编号
    char Pos_name[50];    //职位名称
    double Pos_salary_min;//职位最低工资
    double Pos_salary_max;//职位最高工资
    int Pos_person_num;  //职位人数
    struct Department *Department_ptr;  //部门指针
    struct Pos *Pos_node;    //链表指针
};

typedef struct Department  //部门
{
    char *Department_ID;  //部门编号 8位  [10]
    char *Department_name; //部门名称      [30]
    char *Manager_name;    //部门主管姓名   [25]
    char *Established_time;//输入的时候给提示，部门成立时间    [15]
    int Department_person_num; //部门人数
    struct Pos *Pos_ptr;         //职位指针
    struct Department *Department_node;  //链表指针
};







#endif // STRUCTNAME_H_INCLUDED

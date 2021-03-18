#ifndef LR_2_1_H
#define LR_2_1_H
#define USDB 0.385653683
#define EURB 0.323834197
#define RUBB 29.06976744

#define USDS 0.384319754
#define EURS 0.321853878
#define RUBS 28.08988764

#define USDN 0.38583224
#define EURN 0.32364554
#define RUBN 28.137310

double MoneyIn();
double ConvertUSDB(double *Money);
double ConvertEURB(double *Money);
double ConvertRUBB(double *Money);
double ConvertUSDS(double *Money);
double ConvertEURS(double *Money);
double ConvertRUBS(double *Money);
double ConvertUSDN(double *Money);
double ConvertEURN(double *Money);
double ConvertRUBN(double *Money);
void SpreaDsheet();
void Profit();
void Convert(double *Money);
int Validation(short *x);
void StarLine();
void Info();
#endif
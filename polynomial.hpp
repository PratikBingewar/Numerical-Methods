class Polynomial
{
  public:
    double *polynomial;
    int degree;
    Polynomial(int d = 1);
    // Polynomial(const Polynomial &);
    void operator=(const Polynomial &);
    int accept();
    void display() const;
    double evaluate(double) const;
    double bisection() const;
    double regulafalse() const;
    double root(char token = 'b') const;
    Polynomial derivative() const;
    double newtonRaphson() const;
    double secantMethod() const;
};
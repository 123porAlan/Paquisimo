class Rueda {
public:
    // Métodos comunes para todas las ruedas
    virtual void avanzar(int velocidad) = 0;
    virtual void retroceder(int velocidad) = 0;
    virtual void frenar() = 0;
    virtual void configurarPines(int pinAtras, int pinAdelante, int pinPwmAtras, int pinPwmAdelante) = 0;
};

// Implementación de una rueda específica
class RuedaDelanteraDerecha : public Rueda {
private:
    int pinAtras, pinAdelante, pinPwmAtras, pinPwmAdelante;
public:
    void configurarPines(int pinAtras, int pinAdelante, int pinPwmAtras, int pinPwmAdelante) override {
        this->pinAtras = pinAtras;
        this->pinAdelante = pinAdelante;
        this->pinPwmAtras = pinPwmAtras;
        this->pinPwmAdelante = pinPwmAdelante;
        // Configuración de pines como salida
        pinMode(pinAtras, OUTPUT);
        pinMode(pinAdelante, OUTPUT);
        pinMode(pinPwmAtras, OUTPUT);
        pinMode(pinPwmAdelante, OUTPUT);
    }

    void avanzar(int velocidad) override {
        analogWrite(pinPwmAdelante, velocidad);
        digitalWrite(pinAtras, LOW);
        digitalWrite(pinAdelante, HIGH);
    }

    void retroceder(int velocidad) override {
        analogWrite(pinPwmAtras, velocidad);
        digitalWrite(pinAdelante, LOW);
        digitalWrite(pinAtras, HIGH);
    }

    void frenar() override {
        digitalWrite(pinAtras, LOW);
        digitalWrite(pinAdelante, LOW);
    }
};


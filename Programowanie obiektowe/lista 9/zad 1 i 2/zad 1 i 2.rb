# Marcin Banak
# Lista 9, zadanie 1 oraz 3.
# Program kompiluje przy pomocy kompilatora online na stronie "replit.com" 
# poprzez kliknięcie przycisku "run" dla danego projektu.

class Function
  def initialize(&f)
    @func = f
  end
  def value(x)
    @func.call(x)
  end
  # Funckja znajduje miejsce zerowe, 
  # przy użyciu algorytmu wyszukiwania binarnego
  def zero(a, b, e)
    if (self.value(a)).abs <= e
      return a
    end
  
    if (self.value(b)).abs <= e
      return b
    end
  
    c = (a + b) / 2.0
    while (b - a) > e
      #print(a, ' ', b, ' ', c, "\n")
      if (self.value(c)).abs <= e
        return c
      elsif self.value(a) * self.value(c) < 0
        b = c
      else
        a = c
      end
      c = (a + b) / 2.0
    end
  
    nil
  end
  # Funckja oblicza pole pod wykresem metodą trapezów.
  def field(a, b)
    n = 1000 # Ilość trapezów.
    h = (b - a).abs / n.to_f # Wysokość trapezów.

    sum = (self.value(a) + self.value(b)) / 2.0 # Krańce przedziału.
    (1...n).each do |i|
      sum += self.value(a + i * h)
    end

    sum * h
  end
  # Funkcja oblicz pochodną funkcji x z definicji pochodnej:
  # f'(x) = lim h -> 0 (f(x+h) - f(x)) / h.
  def deriv(x, h = 1e-6)
    (self.value(x + h) - self.value(x)) / h
  end
  def plot(a, b)
    width = 70
    height = 40
    values = Array.new(width + 1)
    x_step = (b - a).abs / width.to_f

    # Określenie wartości dla punktów odległych od siebie o x_step.
    min = max = self.value(a)
    (0..width).each do |i|
      values[i] = self.value(a + i * x_step)
      if max < values[i]
        max = values[i]
      end
      if min > values[i]
        min = values[i]
      end
    end

    # Wypisanie wykresu.
    val_step = (max - min) / height.to_f
    (0..height).each do |i|
      printf("%7.2f", max - i * val_step)
      (0..width).each do |j|
        if values[j].round == (max - i * val_step).round
          print('*')
        else
          print(' ')
        end
      end
      print("\n")
    end
    print("       ")
    step = (width / 5) * x_step
    (0..5).each do |i|
      printf("%7.2f", a + i * step)
      (0...(width/5 - 7)).each do
        print(' ')
      end
    end
  end
end

f = Function.new { |x| 2 * x + 3 }
h = Function.new { |x| x**2 + 3 * x - 5}

print("Miejsce zerowe funkcji f(x) = 2x + 3:\n")
printf("%.4f\n", f.zero(-10, 10, 0.1))

print("Pole pod wykresem funkcji f(x) = 2x + 3 w przedziale <0, 10>:\n")
printf("%.4f\n", f.field(0, 10))

print("Wartość pochodnej funkcji h(x) = x^2 + 3x - 5 w punkcie x = 6:\n")
printf("%.4f\n\n\n\n", h.deriv(6))

printf("wykres funkcji f(x) = 2x + 3 w przedziale <0, 100>\n")
f.plot(0, 100)

printf("\n\n\n\nwykres funkcji h(x) = x^2 + 3x - 5 w przedziale <0, 10>\n")
h.plot(-10, 10)
  
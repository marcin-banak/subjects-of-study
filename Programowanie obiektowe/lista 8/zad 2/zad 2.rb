# Marcin Banak
# Lista 8, zadanie 1.
# Program kompiluje przy pomocy kompilatora online na stronie
# "replit.com" poprzez kliknięcie przycisku "run" dla danego projektu.

# Definicje klas podstawowych.

# Klasa przechowuje masę w kilogramach.
class Mass
  def initialize(temp)
    @kg = temp
  end
  def kg
    @kg
  end
  def kg=(temp)
    @kg = temp
  end
  def pound
    @kg * 2.2046
  end
  def pound=(temp)
    @kg = temp * 0.4535
  end
end

# Klasa przechowuje długość w metrach.
class Length
  def initialize(temp)
    @meter = temp
  end
  def meter
    @meter
  end
  def meter=(temp)
    @meter = temp
  end
  def feet
    @meter * 3.2808
  end
  def feet=(temp)
    @meter = temp * 0.3048
  end
end

# Testy dla powyższych klas.
mass = Mass.new(2)
print('kg: ', mass.kg, ' = pound: ', mass.pound, "\n")

length = Length.new(5)
print('m: ', length.meter, ' = feet: ', length.feet, "\n\n")

# Definicje klas pochodnych.

# Klasa przechowuje pole powierzchni w hektarach.
class Area
  def initialize(temp)
    @length = Length.new(temp)
  end
  def hectare
    @length.meter**2 / 10000
  end
  def hectare=(temp)
    @length.meter = Math.sqrt(temp * 10000)
  end
  def sqInch
    (@length.feet * 12)**2
  end
  def sqInch=(temp)
    @length.feet = Math.sqrt(temp / 144)
  end
end

# Klasa przechowuje ciśnienie jako kilogram na metr kwadratowy.
class Pressure
  def initialize(mass, area)
    @mass = Mass.new(mass)
    @area = Area.new(area)
  end
  def bar
    @mass.kg / (@area.hectare * 10000)
  end
  def bar=(args)
    @mass.kg = args[0]
    @area.hectare = args[1]
  end
  def psi
    @mass.pound / (@area.sqInch / 144)
  end
  def psi=(args)
    @mass.pound = args[0]
    @area.sqInch = args[1]
  end
end

area = Area.new(0)
print("hectare | square inch\n")
for i in 1..5 do
  area.hectare = i
  puts "%0.2f    | %0.2f\n" % [area.hectare, area.sqInch]
end

pressure = Pressure.new(0, 0)
print("\nbar     | psi\n")
for i in 1..5 do
  pressure.bar = [i * i * 100000, i]
  puts "%0.2f   | %0.2f\n" % [pressure.bar, pressure.psi]
end
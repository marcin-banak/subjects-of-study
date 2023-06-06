# Marcin Banak
# Lista 8, zadanie 4.
# Program kompiluje przy pomocy kompilatora online na stronie "replit.com" 
# poprzez kliknięcie przycisku "run" dla danego projektu.

class Jawna
  def initialize(temp)
    @napis = temp
  end

  # Funkcja szyfrująca.
  def zaszyfruj(klucz)
    zaszyfrowany = ''
    @napis.each_char do |c|
      zaszyfrowany += if c >= 'a' and c <= 'z'
                        klucz[c]
                      else
                        c
                      end
    end
    zaszyfrowany
  end

  def to_s
    @napis
  end
end

class Zaszyfrowana
  def initialize(temp)
    @napis = temp
  end

  # Funkcja deszyfrująca
  def odszyfruj(klucz)
    zaszyfrowany = ''
    @napis.each_char do |c|
      zaszyfrowany += if c >= 'a' and c <= 'z'
                        klucz[c]
                      else
                        c
                      end
    end
    zaszyfrowany
  end

  def to_s
    @napis
  end
end

klucz = {
  'a' => 'z',
  'b' => 'y',
  'c' => 'x',
  'd' => 'w',
  'e' => 'v',
  'f' => 'u',
  'g' => 't',
  'h' => 's',
  'i' => 'r',
  'j' => 'q',
  'k' => 'p',
  'l' => 'o',
  'm' => 'n',
  'n' => 'm',
  'o' => 'l',
  'p' => 'k',
  'q' => 'j',
  'r' => 'i',
  's' => 'h',
  't' => 'g',
  'u' => 'f',
  'v' => 'e',
  'w' => 'd',
  'x' => 'c',
  'y' => 'b',
  'z' => 'a'
}

# Pole @napis klasy Jawna ustawiam na 'napis1'.
jawna = Jawna.new('napis1')
# Wypisuje zaszyfrowany napis.
print(jawna.zaszyfruj(klucz))

# Pole @napis klasy Zaszyfrowana ustawiam na 'napis1' po zaszyfrowaniu.
zaszyfrowana = Zaszyfrowana.new(jawna.zaszyfruj(klucz))
# Wypisuje odszyfrowany napis.
print(' = ', zaszyfrowana.odszyfruj(klucz))

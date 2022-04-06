import unittest
import string
import passcomplexity

class TestPassComplexity(unittest.TestCase):
  def test_complexity(self):
    self.assertTrue(passcomplexity.is_complex('RrbD@!pWcLzstQfyskZ7U'))
    self.assertTrue(passcomplexity.is_complex('complexPass123!'))
    self.assertTrue(passcomplexity.is_complex('321complex!Pass'))

  def test_insecurity(self):
    self.assertFalse(passcomplexity.is_complex('.'))
    self.assertFalse(passcomplexity.is_complex('1a2b3c4d'))
    self.assertFalse(passcomplexity.is_complex('FWaFW12321'))

  def test_invalid_passwords(self):
    self.assertFalse(passcomplexity.is_complex(''))
    for i in string.whitespace.replace('\n', ''):
      self.assertFalse(passcomplexity.is_complex('ComplexPass123!' + i))

  def test_generated_complexity(self):
    for i in range(5):
      self.assertTrue(passcomplexity.is_complex(passcomplexity.gen_password()))

  def test_randomness(self):
    password = passcomplexity.gen_password()
    for i in range(5):
      self.assertNotEqual(password, passcomplexity.gen_password())

if __name__ == '__main__':
  unittest.main()

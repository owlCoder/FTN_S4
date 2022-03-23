using System;
using System.Collections.Generic;
using System.IO;

namespace Restoran
{
    class Restoran
    {
        private string naziv;
        private string adresa;
        private List<Stavka> jelovnik;

        public Restoran(string naziv, string adresa)
        {
            this.Naziv = naziv;
            this.Adresa = adresa;
            jelovnik = new List<Stavka>();
        }

        public string Naziv { get => naziv; set => naziv = value; }
        public string Adresa { get => adresa; set => adresa = value; }
        public List<Stavka> Stavke { get => jelovnik; set => jelovnik = value; }

        public override string ToString()
        {
            string str = "Restoran \"" + naziv + "\"\nAdresa: " + adresa + "\n";
            str += "\nJelovnik\n***********************\n";
            foreach(Stavka s in jelovnik)
            {
                str += s.Naziv + " " + s.Cena + "\n";
            }
            str += "***********************\n";

            return str;
        }

        public void Import(string putanja)
        {
            using (TextReader txtReader = new StreamReader(File.Open(putanja, FileMode.Open)))
            {
                if (File.Exists(putanja))
                {
                    while (true)
                    {
                        string str = txtReader.ReadLine();
                        if (str == null)
                        {
                            break;
                        }

                        string[] splitovano = str.Split('|');                        
                        foreach(Stavka s in jelovnik)
                        {
                            if(s.Naziv.Equals(splitovano[0]))
                            {
                                break; // vec postoji ne dodajemo isti naziv
                            }    
                        }
                        Stavka tmp = new Stavka(splitovano[0], double.Parse(splitovano[1]));
                        jelovnik.Add(tmp);
                    }

                    txtReader.Close();
                }
                else
                {
                    Console.WriteLine("\nDatoteka ne postoji!");
                }
            }
        }

        public void Sortiraj()
        {
            jelovnik.Sort((s1, s2) => s1.Cena.CompareTo(s2.Cena));
            jelovnik.Reverse();
        }

        public void Export(string putanja)
        {
            using (TextWriter txtWriter = new StreamWriter(File.Open(putanja, FileMode.Create)))
            {
                txtWriter.WriteLine("Restoran \"" + naziv + "\"");
                txtWriter.WriteLine("Adresa: " + adresa);
                txtWriter.WriteLine("Jelovnik\n");
                txtWriter.WriteLine("******************");

                foreach (Stavka s in jelovnik)
                {
                    txtWriter.WriteLine(s.Naziv + " " + s.Cena);
                }
                txtWriter.WriteLine("******************");

                txtWriter.Close();
            }
        }
    }
}

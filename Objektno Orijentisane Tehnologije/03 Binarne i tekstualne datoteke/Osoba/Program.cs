using System;
using System.Collections.Generic;
using System.IO;

namespace Osoba
{
    class Program
    {
        static void Main(string[] args)
        {
            Osoba o1 = new Osoba("Danijel", "Jovanovic");
            Osoba o2 = new Osoba("Milena", "Kovacevic");
            Osoba o3 = new Osoba(" ", " ");

            List<Osoba> osobe = new List<Osoba>();
            List<Osoba> osobe_read = new List<Osoba>();
            osobe.Add(o1); osobe.Add(o2); osobe.Add(o3);
            osobe.Add(o1); osobe.Add(o2); osobe.Add(o3);

            Console.Write(o1);
            Console.Write(o2);

            snimiOsobu(o1);
            snimiOsobu(o2);

            ucitajOsobu(o3);
            Console.WriteLine("\nUcitana osoba\n" + o3);

            snimiOsobe(osobe);
            ucitajOsobe(osobe_read);

            Console.WriteLine("\nOsobe iz liste txt: ");
            foreach(Osoba o in osobe_read)
            {
                Console.Write(o);
            }
        }
        static void snimiOsobu(Osoba o)
        {
            using (BinaryWriter binWriter = new BinaryWriter(File.Open("osoba.dat", FileMode.Append)))
            {
                binWriter.Write(o.Ime);
                binWriter.Write(o.Prezime);
                binWriter.Write("\n");

                binWriter.Close();
            }
        } 

        static void ucitajOsobu(Osoba o)
        {
            using (BinaryReader binReader = new BinaryReader(File.Open("osoba.dat", FileMode.Open)))
            {
                string ime = binReader.ReadString();
                string prezime = binReader.ReadString();

                o.Ime = ime;
                o.Prezime = prezime;

                binReader.Close();
            }
        }

        static void snimiOsobe(List<Osoba> osobe)
        {
            using (TextWriter txtWriter = new StreamWriter(File.Open("osobe.txt", FileMode.Append)))
            {
                foreach(Osoba o in osobe)
                {
                    txtWriter.WriteLine(o.Ime + " " + o.Prezime);
                }

                txtWriter.Close();
            }
        }

        static void ucitajOsobe(List<Osoba> osobe)
        {
            using (TextReader txtReader = new StreamReader(File.Open("osobe.txt", FileMode.Open)))
            {
                if(File.Exists("osobe.txt"))
                {
                    while (true)
                    {
                        string str = txtReader.ReadLine();
                        if(str == null)
                        {
                            break;
                        }

                        string[] splitovano = str.Split(' ');
                        Osoba tmp = new Osoba(splitovano[0], splitovano[1]);
                        osobe.Add(tmp);
                    }

                    txtReader.Close();
                }
                else
                {
                    Console.WriteLine("\nDatoteka ne postoji!");
                }
            }
        }
    }
}

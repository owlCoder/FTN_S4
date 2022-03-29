using System.IO;

namespace PripremaK1
{
    class App
    {
        public static string LoadFromFile(string putanja)
        {
            string sadrzaj = "";

            using (TextReader txt = new StreamReader(File.Open(putanja, FileMode.Open)))
            {
                while(true)
                {
                    string red = txt.ReadLine();

                    if(red == null)
                    {
                        break;
                    }

                    sadrzaj += red;
                }
                txt.Close();
            }
            return sadrzaj;
        }

        public static void SaveToFile(string zaUpis, string putanja)
        {
            using(TextWriter tw = new StreamWriter(File.Open(putanja, FileMode.Create)))
            {
                tw.WriteLine(zaUpis);
                tw.Close();
            }
        }
    }
}

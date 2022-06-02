using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Biblioteka.Korisnici
{
    public partial class DodajKorisnika : Page
    {
        private string trenutnaPutanja = string.Empty;
        public DodajKorisnika()
        {
            InitializeComponent();
        }
        private void slikaKorisnika_Click(object sender, RoutedEventArgs e)
        {
            Program.OdabirPutanjeDatoteke odabir = new Program.OdabirPutanjeDatoteke();
            trenutnaPutanja = odabir.Odabir_Putanje("korisnika", slika);
        }

        private void dodajKorisnikaBtn_Click(object sender, RoutedEventArgs e)
        {
            if (imeKorisnika.Text.Equals("") || prezimeKorisnika.Text.Equals("") || jmbgKorisnika.Text.Equals("") || trenutnaPutanja.Equals(""))
            {
                MessageBox.Show("Niste popunili sva polja!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                try
                {
                    Korisnik novi = new Korisnik(imeKorisnika.Text, prezimeKorisnika.Text, jmbgKorisnika.Text, trenutnaPutanja, "NIJE");
                    App.SviKorisnici.Add(novi);
                    slika.Source = new BitmapImage(new Uri("/Slike/placeholder.png", UriKind.Relative));
                }
                catch
                {
                    MessageBox.Show("Nije uspeo pokušaj dodavanja korisnika u kolekciju!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
                }

                MessageBox.Show("Korisnik uspešno dodat!", "Informacija!", MessageBoxButton.OK, MessageBoxImage.Information);

                imeKorisnika.Clear();
                prezimeKorisnika.Clear();
                jmbgKorisnika.Clear();
                trenutnaPutanja = string.Empty;
            }

        }
    }
}

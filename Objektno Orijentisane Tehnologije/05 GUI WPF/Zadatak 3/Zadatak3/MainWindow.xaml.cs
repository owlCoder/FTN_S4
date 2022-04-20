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

namespace GUI1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private static int brojac = 0;
        public MainWindow()
        {
            InitializeComponent();
        }
        private void GenerisanjeBtn_Click(object sender, RoutedEventArgs e)
        {
            bool notEmpty = ProveriPoljaForme();

            if (!notEmpty)
            {
                Random rnd = new Random();
                string username = Ime.Text + "_" + Prezime.Text + rnd.Next();
                GenerisanUsername.Text = username;
            }
        }

        private void OcistiPolja_Click(object sender, RoutedEventArgs e)
        {
            Ime.Clear();
            Prezime.Clear();
            GenerisanUsername.Clear();
        }

        private void SacyvajBtn_Click(object sender, RoutedEventArgs e)
        {
            bool notEmpty = ProveriPoljaForme();

            if (!notEmpty && GenerisanUsername.Text != "")
            {
                brojac += 1;
                PoslednjeGenerisano.Text = GenerisanUsername.Text;
                UkupnoGenerisano.Text = brojac.ToString();

                // Otkljucavanje polja za cuvanje lozinke
                Lozinka.IsEnabled = true;
                Lozinka.Background = Brushes.White;
                Lozinka.Text = String.Empty;

                MessageBox.Show("Mozete uneti lozinku!", "Informacija!", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                MessageBox.Show("Niste generisali korisnicko ime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private bool ProveriPoljaForme()
        {
            bool notEmpty = false;

            if (Ime.Text.Equals(""))
            {
                MessageBox.Show("Niste uneli ime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
                notEmpty = true;
            }

            if (Prezime.Text.Equals(""))
            {
                MessageBox.Show("Niste uneli prezime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
                notEmpty = true;
            }

            return notEmpty;
        }

        private void ResetujSveBtn_Click(object sender, RoutedEventArgs e)
        {
            brojac = 0;
            OcistiPolja_Click(sender, e);
            PoslednjeGenerisano.Text = string.Empty;
            Lozinka.Text = string.Empty;
            UkupnoGenerisano.Text = "0";
        }

        private void Lozinka_LostFocus(object sender, RoutedEventArgs e)
        {
            if(Lozinka.Text.Equals(GenerisanUsername.Text) || Lozinka.Text.Equals(""))
            {
                MessageBox.Show("Korisnicko ime NE SME BITI LOZINKA ili PRAZNO POLJE!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                MessageBox.Show("Lozinka za korisnika sacuvana!\nIzmene onemogucene!", "Informacija!", MessageBoxButton.OK, MessageBoxImage.Information);
                Lozinka.IsEnabled = false;
            }

        }
    }
}

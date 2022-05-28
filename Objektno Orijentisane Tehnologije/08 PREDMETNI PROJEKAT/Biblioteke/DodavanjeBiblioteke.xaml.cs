using System;
using System.Windows;
using System.Windows.Controls;

namespace OOT_PP_PR83_PR55_2020_BIBLIOTEKA.Biblioteka
{
    public partial class DodavanjeBiblioteke : Page
    {
        private static string trenutnaPutanja = string.Empty;
        public DodavanjeBiblioteke()
        {
            InitializeComponent();
        }

        private void logoBiblioteke_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.FileName = "";
            dialog.DefaultExt = ".png"; 
            dialog.Filter = "SLIKA (.png)|*.png"; 

            bool ? result = dialog.ShowDialog();

            if (result == true)
            {
                trenutnaPutanja = dialog.FileName;
            }
            else
            {
                MessageBox.Show("Niste odabrali logo biblioteke!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
                trenutnaPutanja = string.Empty;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(nazivBiblioteke.Equals("") || adresaBiblioteke.Equals("") || godinaOsnivanjaBiblioteke.Equals("") || trenutnaPutanja.Equals(""))
            {
                MessageBox.Show("Niste popunila sva polja!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                int broj = -1;
                bool uspesno = false;

                try
                {
                    broj = int.Parse(godinaOsnivanjaBiblioteke.Text);
                    uspesno = true;
                }
                catch(Exception)
                {
                    MessageBox.Show("Niste uneli broj!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
                }

                if(uspesno)
                {
                    // parsiraj ostale podatke
                    Biblioteka_ nova = new Biblioteka_(nazivBiblioteke.Text, adresaBiblioteke.Text, broj, trenutnaPutanja);
                    App.Biblioteke.Add(nova);

                    MessageBox.Show("Biblioteka dodata u listu!", "Informacija!", MessageBoxButton.OK, MessageBoxImage.Information);
                    nazivBiblioteke.Clear();
                    adresaBiblioteke.Clear();
                    godinaOsnivanjaBiblioteke.Clear();
                    trenutnaPutanja = string.Empty;
                }
                else
                {
                    MessageBox.Show("Nije moguće dodati biblioteku!", "Greška!", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }
    }
}

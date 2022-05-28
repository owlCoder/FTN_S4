﻿using System;
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
using System.Windows.Shapes;

namespace Zadatak4
{
    /// <summary>
    /// Interaction logic for DodavanjeProizvoda.xaml
    /// </summary>
    public partial class DodavanjeProizvoda : Window
    {
        public Kategorija kategorija;

        public DodavanjeProizvoda(Kategorija k)
        {
            kategorija = k;
            InitializeComponent();
        }

        private void Dodaj_Click(object sender, RoutedEventArgs e)
        {
            if (!Double.TryParse(txtCena.Text, out double cena))
            {
                MessageBox.Show("Cena mora biti broj!", "Greška", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            else if (kategorija.Dodaj(new Proizvod()
            {
                Naziv = txtNaziv.Text,
                Cena = cena
            }))
                MessageBox.Show("Uspešno dodavanje!", "Obaveštenje", MessageBoxButton.OK, MessageBoxImage.Information);
            else
                MessageBox.Show("Neuspešno dodavanje!", "Greška", MessageBoxButton.OK, MessageBoxImage.Error);

            this.Close();
        }
    
    }
}

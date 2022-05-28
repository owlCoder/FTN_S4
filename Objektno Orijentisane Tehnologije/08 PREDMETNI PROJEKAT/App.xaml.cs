using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;

namespace OOT_PP_PR83_PR55_2020_BIBLIOTEKA
{
    // KLASA KNJIGA
    class Knjiga : INotifyPropertyChanged
    {
        private string naziv;
        private string autora;
        private int godinaIzdanja;

        public Knjiga(string naziv, string autora, int godinaIzdanja)
        {
            Naziv = naziv;
            Autora = autora;
            GodinaIzdanja = godinaIzdanja;
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string name)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(name));
            }
        }

        public string Naziv { get => naziv; set => naziv = value; }
        public string Autora { get => autora; set => autora = value; }
        public int GodinaIzdanja { get => godinaIzdanja; set => godinaIzdanja = value; }
    }

    // KLASA KORISNIK
    class Korisnik : INotifyPropertyChanged
    {
        private string ime;
        private string prezime;
        private string jmbg;
        private string profilnaSlika;
        private string datumUclanjenja;

        public Korisnik(string ime, string prezime, string jmbg, string profilnaSlika, string datumUclanjenja)
        {
            Ime = ime;
            Prezime = prezime;
            Jmbg = jmbg;
            ProfilnaSlika = profilnaSlika;
            DatumUclanjenja = datumUclanjenja;
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string name)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(name));
            }
        }

        public string Ime
        {
            get
            {
                return ime;
            }

            set
            {
                if (value != ime)
                {
                    ime = value;
                    OnPropertyChanged("Ime");
                }
            }
        }
        public string Prezime
        {
            get
            {
                return prezime;
            }

            set
            {
                if (value != prezime)
                {
                    prezime = value;
                    OnPropertyChanged("Prezime");
                }
            }
        }
        public string Jmbg
        {
            get
            {
                return jmbg;
            }

            set
            {
                if (value != jmbg)
                {
                    jmbg = value;
                    OnPropertyChanged("Jmbg");
                }
            }
        }
        public string ProfilnaSlika
        {
            get
            {
                return profilnaSlika;
            }

            set
            {
                if (value != profilnaSlika)
                {
                    profilnaSlika = value;
                    OnPropertyChanged("ProfilnaSlika");
                }
            }
        }
        public string DatumUclanjenja
        {
            get
            {
                return datumUclanjenja;
            }

            set
            {
                if (value != datumUclanjenja)
                {
                    datumUclanjenja = value;
                    OnPropertyChanged("DatumUclanjenja");
                }
            }
        }
    }

    // KLASA BIBLIOTEKA
    class Biblioteka_ : INotifyPropertyChanged
    {
        private string naziv;
        private string adresa;
        private int godinaOsnivanja;
        private string logoBiblioteke;
        private ObservableCollection<Korisnik> korisnici = new ObservableCollection<Korisnik>();
        private ObservableCollection<Knjiga> knjige = new ObservableCollection<Knjiga>();

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string name)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(name));
            }
        }

        public Biblioteka_(string naziv, string adresa, int godinaOsnivanja, string logoBiblioteke)
        {
            Naziv = naziv;
            Adresa = adresa;
            GodinaOsnivanja = godinaOsnivanja;
            LogoBiblioteke = logoBiblioteke;
        }

        public string Naziv
        {
            get
            {
                return naziv;
            }

            set
            {
                if (value != naziv)
                {
                    naziv = value;
                    OnPropertyChanged("Naziv");
                }
            }
        }
        public string Adresa
        {
            get
            {
                return adresa;
            }

            set
            {
                if (value != adresa)
                {
                    adresa = value;
                    OnPropertyChanged("Adresa");
                }
            }
        }
        public int GodinaOsnivanja
        {
            get
            {
                return godinaOsnivanja;
            }

            set
            {
                if (value != godinaOsnivanja)
                {
                    godinaOsnivanja = value;
                    OnPropertyChanged("GodinaOsnivanja");
                }
            }
        }
        public string LogoBiblioteke
        {
            get
            {
                return logoBiblioteke;
            }

            set
            {
                if (value != logoBiblioteke)
                {
                    logoBiblioteke = value;
                    OnPropertyChanged("LogoBiblioteke");
                }
            }
        }
        internal ObservableCollection<Korisnik> Korisnici { get => korisnici; set => korisnici = value; }
        internal ObservableCollection<Knjiga> Knjige { get => knjige; set => knjige = value; }
    }
    public partial class App : Application
    {
        static ObservableCollection<Knjiga> referencaNaKnjigePoBiblioteci = null;

        static ObservableCollection<Biblioteka_> biblioteke = new ObservableCollection<Biblioteka_>();
        internal static ObservableCollection<Biblioteka_> Biblioteke { get => biblioteke; set => biblioteke = value; }
        internal static ObservableCollection<Knjiga> ReferencaNaKnjigePoBiblioteci { get => referencaNaKnjigePoBiblioteci; set => referencaNaKnjigePoBiblioteci = value; }

        public App()
        {
            // TEST PODACI KASNIJE CE SE UCITAVATI IZ DATOTEKE
            for(int i = 0; i < 50; i++)
            {
                Biblioteka_ nova = new Biblioteka_("NS[" + i + "]", "Alekse Santica " + (i + 1), 1986 + i + 1, "C:/Biblioteke/" + (i + 1) + ".jpg");
                biblioteke.Add(nova);
            }

            for (int i = 0; i < 100; i++)
            {
                Knjiga nova = new Knjiga("KNJIGA[" + i + "]", "Autor " + (i + 1), 1986 + i + 1);
                biblioteke[i % 5].Knjige.Add(nova);
            }
        }
    }
}

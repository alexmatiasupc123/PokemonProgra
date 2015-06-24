#pragma once
#include "Juego.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
			juego = new CJuego();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//delete juego;
		}
	protected: 
	private:
		int retraso;
		bool modoRetraso;
		Bitmap ^imgJugador;
		Bitmap ^imgMaestro;
		Bitmap ^imgFondoGimnasio;
		Bitmap ^imgFondoCentroP;
		Bitmap ^imgGimnasio;
		Bitmap ^imgGYM;
		Bitmap ^imgPikachu;
		Bitmap ^imgBatalla;
		Bitmap ^imgCentroP;
		Bitmap ^imgArbol;
		Bitmap ^imgPasto;
		String ^dialogo;
		CJuego *juego;
		CPokemon *miPokemon;
		CPokemon *pokemonRival;
		int numtexto;
		int x,y;
		int mov;
		int indiceEliminar;

	private: System::Windows::Forms::Panel^  panelTexto;
	private: System::Windows::Forms::Label^  lblTexto;
	private: System::Windows::Forms::Timer^  timerBatalla;
	private: System::Windows::Forms::Timer^  timerGimnasio;
	private: System::Windows::Forms::Timer^  timerMapa;
	private: System::Windows::Forms::Button^  btnCapturar;


	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ProgressBar^  pgPokemonRival;
	private: System::Windows::Forms::ProgressBar^  pgMiPokemon;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Timer^  timerCentroP;
	private: System::Windows::Forms::PictureBox^  pbBatalla;
	private: System::Windows::Forms::Timer^  retrasoContraAtaque;
	private: System::ComponentModel::IContainer^  components;
	private:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnCapturar = (gcnew System::Windows::Forms::Button());
			this->pgPokemonRival = (gcnew System::Windows::Forms::ProgressBar());
			this->pgMiPokemon = (gcnew System::Windows::Forms::ProgressBar());
			this->panelTexto = (gcnew System::Windows::Forms::Panel());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->lblTexto = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->timerBatalla = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerGimnasio = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMapa = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerCentroP = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbBatalla = (gcnew System::Windows::Forms::PictureBox());
			this->retrasoContraAtaque = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelTexto->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBatalla))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCapturar
			// 
			this->btnCapturar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnCapturar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCapturar->Enabled = false;
			this->btnCapturar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCapturar.Image")));
			this->btnCapturar->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnCapturar->Location = System::Drawing::Point(811, 56);
			this->btnCapturar->Name = L"btnCapturar";
			this->btnCapturar->Size = System::Drawing::Size(77, 55);
			this->btnCapturar->TabIndex = 16;
			this->btnCapturar->Text = L"&Capturar";
			this->btnCapturar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnCapturar->UseVisualStyleBackColor = true;
			this->btnCapturar->Visible = false;
			this->btnCapturar->Click += gcnew System::EventHandler(this, &MyForm::btnCapturar_Click);
			// 
			// pgPokemonRival
			// 
			this->pgPokemonRival->Location = System::Drawing::Point(112, 56);
			this->pgPokemonRival->Name = L"pgPokemonRival";
			this->pgPokemonRival->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pgPokemonRival->RightToLeftLayout = true;
			this->pgPokemonRival->Size = System::Drawing::Size(292, 57);
			this->pgPokemonRival->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->pgPokemonRival->TabIndex = 15;
			this->pgPokemonRival->Value = 100;
			this->pgPokemonRival->Visible = false;
			// 
			// pgMiPokemon
			// 
			this->pgMiPokemon->Location = System::Drawing::Point(596, 328);
			this->pgMiPokemon->Name = L"pgMiPokemon";
			this->pgMiPokemon->Size = System::Drawing::Size(292, 57);
			this->pgMiPokemon->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->pgMiPokemon->TabIndex = 14;
			this->pgMiPokemon->Value = 100;
			this->pgMiPokemon->Visible = false;
			// 
			// panelTexto
			// 
			this->panelTexto->BackColor = System::Drawing::Color::White;
			this->panelTexto->Controls->Add(this->radioButton4);
			this->panelTexto->Controls->Add(this->listBox1);
			this->panelTexto->Controls->Add(this->radioButton3);
			this->panelTexto->Controls->Add(this->lblTexto);
			this->panelTexto->Controls->Add(this->radioButton2);
			this->panelTexto->Controls->Add(this->radioButton1);
			this->panelTexto->Location = System::Drawing::Point(112, 489);
			this->panelTexto->Name = L"panelTexto";
			this->panelTexto->Size = System::Drawing::Size(776, 91);
			this->panelTexto->TabIndex = 13;
			this->panelTexto->Visible = false;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(562, 72);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(85, 17);
			this->radioButton4->TabIndex = 13;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(653, 7);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 82);
			this->listBox1->TabIndex = 8;
			this->listBox1->Visible = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(562, 49);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(85, 17);
			this->radioButton3->TabIndex = 12;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// lblTexto
			// 
			this->lblTexto->AutoSize = true;
			this->lblTexto->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTexto->Location = System::Drawing::Point(13, 12);
			this->lblTexto->Name = L"lblTexto";
			this->lblTexto->Size = System::Drawing::Size(75, 31);
			this->lblTexto->TabIndex = 2;
			this->lblTexto->Text = L"[text]";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(562, 26);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(85, 17);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(562, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(85, 17);
			this->radioButton1->TabIndex = 10;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			// 
			// timerBatalla
			// 
			this->timerBatalla->Interval = 10;
			this->timerBatalla->Tick += gcnew System::EventHandler(this, &MyForm::timerBatalla_Tick);
			// 
			// timerGimnasio
			// 
			this->timerGimnasio->Interval = 10;
			this->timerGimnasio->Tick += gcnew System::EventHandler(this, &MyForm::timerGimnasio_Tick);
			// 
			// timerMapa
			// 
			this->timerMapa->Enabled = true;
			this->timerMapa->Interval = 10;
			this->timerMapa->Tick += gcnew System::EventHandler(this, &MyForm::timerMapa_Tick);
			// 
			// timerCentroP
			// 
			this->timerCentroP->Interval = 10;
			this->timerCentroP->Tick += gcnew System::EventHandler(this, &MyForm::timerCentroP_Tick);
			// 
			// pbBatalla
			// 
			this->pbBatalla->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBatalla.Image")));
			this->pbBatalla->Location = System::Drawing::Point(99, 152);
			this->pbBatalla->Name = L"pbBatalla";
			this->pbBatalla->Size = System::Drawing::Size(254, 190);
			this->pbBatalla->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbBatalla->TabIndex = 17;
			this->pbBatalla->TabStop = false;
			this->pbBatalla->Visible = false;
			// 
			// retrasoContraAtaque
			// 
			this->retrasoContraAtaque->Interval = 1000;
			this->retrasoContraAtaque->Tick += gcnew System::EventHandler(this, &MyForm::retrasoContraAtaque_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 600);
			this->Controls->Add(this->pbBatalla);
			this->Controls->Add(this->btnCapturar);
			this->Controls->Add(this->pgPokemonRival);
			this->Controls->Add(this->pgMiPokemon);
			this->Controls->Add(this->panelTexto);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pokemon";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->panelTexto->ResumeLayout(false);
			this->panelTexto->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBatalla))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 juego->cargarObjetosDeArchivo("Objetos.dat");
				 pgPokemonRival->Location.X = 49;
				 pgPokemonRival->Location.Y = 134;
				 pgMiPokemon->Location.X = 459;
				 pgMiPokemon->Location.Y = 354;
				 indiceEliminar = -1;

				 imgJugador = gcnew Bitmap("Imagenes/Personaje.png");		imgJugador->MakeTransparent(imgJugador->GetPixel(1, 1));
				 imgMaestro = gcnew Bitmap("Imagenes/Maestro.png");			imgMaestro->MakeTransparent(imgMaestro->GetPixel(1, 1));
				 imgArbol = gcnew Bitmap("Imagenes/Arbol.png");				imgArbol->MakeTransparent(imgArbol->GetPixel(1,1));
				 imgGimnasio = gcnew Bitmap("Imagenes/casa.png");		imgGimnasio->MakeTransparent(imgGimnasio->GetPixel(1,1));
				 imgCentroP = gcnew Bitmap("Imagenes/CentroPokemon.png");	
				 imgPikachu = gcnew Bitmap("Imagenes/Pikachu.gif"); 
				 imgPasto = gcnew Bitmap("Imagenes/Pasto.png");
				 imgFondoGimnasio = gcnew Bitmap("Imagenes/FondoGimnasio.png");
				 imgFondoCentroP = gcnew Bitmap("Imagenes/FondoCentroP.jpg");
				 imgGYM = gcnew Bitmap("Imagenes/GYM.png");
				 imgBatalla = gcnew Bitmap(pbBatalla->Image); 

				 mov = 0;
				 numtexto = 0;
				 retraso = 0;
				 modoRetraso = false;
			 }
	private: void ingresarAlGimnasio()
			 {
				 timerMapa->Enabled = false;
				 timerGimnasio->Enabled = true;
				 juego->getJugador()->guardarPos();
				 juego->getJugador()->setx(460);
				 juego->getJugador()->sety(540);
			 }
	private: void ingresarAlCentroP()
			 {
				 timerMapa->Enabled = false;
				 timerCentroP->Enabled = true;
				 juego->getJugador()->guardarPos();
				 juego->getJugador()->setx(460);
				 juego->getJugador()->sety(540);
				 juego->getJugador()->regenerarPokemones();
			 }
	private: System::Void timerMapa_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Graphics^ g = this->CreateGraphics();
				 BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				 BufferedGraphics^ buffer = context->Allocate(g, this->DisplayRectangle);
				 buffer->Graphics->Clear(Color::FromArgb(110,205,115));

				 juego->pintarMapa(buffer->Graphics,imgJugador,imgArbol,imgGimnasio,imgCentroP,imgPasto,imgGYM);
				 juego->pintarPokemonesSilvestres(buffer->Graphics,imgPikachu);
				 lblTexto->Text = dialogo;

				 buffer->Render(g);
				 delete buffer;
				 delete g;
			 }
	private: System::Void timerBatalla_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Graphics^ g = this->CreateGraphics();
				 BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				 BufferedGraphics^ buffer = context->Allocate(g, this->DisplayRectangle);
				 buffer->Graphics->Clear(Color::Black);

				 buffer->Graphics->DrawImage(imgBatalla, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
				 buffer->Graphics->DrawImage(imgPikachu,120,280,200,200);
				 buffer->Graphics->DrawImage(imgPikachu,500,80,200,200);
				 if(numtexto>2)
				 {
					 if (miPokemon->getVidaActual() > 0)
						 pgMiPokemon->Value = miPokemon->getVidaActual();
					 else
						 pgMiPokemon->Value = 0;

					 pgPokemonRival->Value = pokemonRival->getVidaActual();
				 }
				 lblTexto->Text = dialogo;

				 buffer->Render(g);
				 delete buffer;
				 delete g;
			 }
	private: System::Void timerGimnasio_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Graphics^ g = this->CreateGraphics();
				 BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				 BufferedGraphics^ buffer = context->Allocate(g, this->DisplayRectangle);
				 buffer->Graphics->Clear(Color::Black);

				 buffer->Graphics->DrawImage(imgFondoGimnasio, 250, 0, 500, this->ClientSize.Height);
				 juego->pintarGimnasio(buffer->Graphics, imgJugador,imgMaestro);	

				 buffer->Render(g);
				 delete buffer;
				 delete g;
			 }
	private: System::Void timerCentroP_Tick(System::Object^  sender, System::EventArgs^  e) 
			{				 
				 Graphics^ g = this->CreateGraphics();
				 BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				 BufferedGraphics^ buffer = context->Allocate(g, this->DisplayRectangle);
				 buffer->Graphics->Clear(Color::Black);
				 buffer->Graphics->DrawImage(imgFondoCentroP, 0, 0,ClientSize.Width,ClientSize.Height);
				 juego->pintarCentroP(buffer->Graphics,imgJugador);
				 buffer->Render(g);
				 delete buffer;
				 delete g;
			 }
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {

				 if(timerMapa->Enabled == true)
				 {
					 if(panelTexto->Visible == false)
					 {
						 if(e->KeyCode == Keys::S)
							 juego->guardarObjetosEnArchivo("Objetos.dat");
						 //derecha
						 if(e->KeyCode == Keys::Right)
						 {
							 if(juego->colisionObjetos(+5,0) == -1)
								 juego->getJugador()->mover(1);
							 if(juego->colisionObjetos(+5,0)==3)
								 ingresarAlGimnasio();
							 if(juego->colisionObjetos(+5,0) == 2)
								 ingresarAlCentroP();
							 indiceEliminar = juego->colisionPokemon(+5, 0);
							 if (indiceEliminar!=-1)
							 {
								 if (juego->getJugador()->pokemonesTienenVida())
									 panelTexto->Visible = true;
								 else
								 {
									 MessageBox::Show("Su pokemon esta debilitado, vaya a un centro PKMN");
									 return;
								 }
							 }
						 }
						 //izquierda
						 if(e->KeyCode == Keys::Left)
						 {
							 if(juego->colisionObjetos(-5,0) == -1)
								 juego->getJugador()->mover(2);
							 if (juego->colisionObjetos(-5, 0)==3)
								 ingresarAlGimnasio();
							 if(juego->colisionObjetos(-5,0) == 2)
								 ingresarAlCentroP();
							 indiceEliminar = juego->colisionPokemon(+5, 0);
							 if (indiceEliminar != -1)
							 {
								 if (juego->getJugador()->pokemonesTienenVida())
									 panelTexto->Visible = true;
								 else
								 {
									 MessageBox::Show("Su pokemon esta debilitado, vaya a un centro PKMN");
									 return;
								 }
							 }
						 }
						 //arriba
						 if(e->KeyCode == Keys::Up)
						 {
							 if(juego->colisionObjetos(0,-5) == -1)
								 juego->getJugador()->mover(3);
							 if (juego->colisionObjetos(0,-5)==3)
								 ingresarAlGimnasio();
							 if(juego->colisionObjetos(0,-5) == 2)
								 ingresarAlCentroP();
							 indiceEliminar = juego->colisionPokemon(+5, 0);
							 if (indiceEliminar != -1)
							 {
								 if (juego->getJugador()->pokemonesTienenVida())
									 panelTexto->Visible = true;
								 else
								 {
									 MessageBox::Show("Su pokemon esta debilitado, vaya a un centro PKMN");
									 return;
								 }
							 }
						 }
						 //abajo
						 if(e->KeyCode == Keys::Down)
						 {
							 if(juego->colisionObjetos(0,+5) == -1)
								 juego->getJugador()->mover(4);
							 if (juego->colisionObjetos(0,+5) == 3)
								 ingresarAlGimnasio();
							 if(juego->colisionObjetos(0,+5) == 2)
								 ingresarAlCentroP();
							 indiceEliminar = juego->colisionPokemon(+5, 0);
							 if (indiceEliminar != -1)
							 {
								 if (juego->getJugador()->pokemonesTienenVida())
									 panelTexto->Visible = true;
								 else
								 {
									 MessageBox::Show("Sus pokemones están debilitados, vaya a un centro PKMN");
									 return;
								 }
							 }
						 }
					 }
					 //dialogos al encontrar un pokemon
					 if(e->KeyCode == Keys::Enter)
					 {
						 numtexto++;
						 switch (numtexto)
						 {   
							 case 1: dialogo = "Has encontrado un pokemón silvestre..!"; break;
							 case 2: dialogo = "Preparate para la batalla..!"; break;
							 case 3: numtexto = 0;
									 timerMapa->Enabled = false;
									 timerBatalla->Enabled = true;
						 }
					 }
				 }
				 if(timerGimnasio->Enabled == true)
				 {
					 //para salir del gimnasio
					 if(e->KeyCode == Keys::Escape)
					 {
						 juego->getJugador()->regresarPos();
						 timerGimnasio->Enabled = false;
						 timerMapa->Enabled = true;
					 }
					 //movimientos del personaje
					 if (e->KeyCode == Keys::Right	&& juego->getJugador()->getx() < 540)
						 juego->getJugador()->mover(1);
					 if (e->KeyCode == Keys::Left	&& juego->getJugador()->getx() > 430)
						 juego->getJugador()->mover(2);
					 if (e->KeyCode == Keys::Up		&& juego->getJugador()->gety() > 125)
						 juego->getJugador()->mover(3);
					 if (e->KeyCode == Keys::Down	&& juego->getJugador()->gety() < 560)
						 juego->getJugador()->mover(4);
				 }
				 if(timerBatalla->Enabled == true)
				 {
					 //para salir de una batalla
					 if(e->KeyCode == Keys::Escape)
					 {
						 timerBatalla->Enabled = false;
						 timerMapa->Enabled = true;
						 pgMiPokemon->Visible = false;
						 pgPokemonRival->Visible = false;
						 panelTexto->Visible = false;
						 btnCapturar->Visible = false;
						 numtexto = 0;
						 radioButton1->Visible = false;
						 radioButton2->Visible = false;
						 radioButton3->Visible = false;
						 radioButton4->Visible = false;
						 dialogo = "";
					 }
					 if(e->KeyCode == Keys::Enter && modoRetraso==false)
					 {
						numtexto++;
						switch (numtexto)
						{   
							case 1: dialogo = "Escoja su pokemon:";
									listBox1->Visible = true;
									listBox1->Focus();
									juego->getJugador()->listar(listBox1);
									listBox1->SelectedIndex = 0;
									break;
							case 2: dialogo = "Que empiece la batalla";
									listBox1->Visible = false;
									miPokemon = juego->getJugador()->getPokemonEnPos(listBox1->SelectedIndex);
									pokemonRival = juego->getPokemonEnPos(0);
									pgMiPokemon->Maximum = miPokemon->getVidaMaxima();
									pgPokemonRival->Maximum = pokemonRival->getVidaMaxima();
									//CUANDO SELECCIONO UN POKEMON DEBILITADO
									if (miPokemon->getVidaActual()>0)
									pgMiPokemon->Value = miPokemon->getVidaActual();
									else
									{
										miPokemon->setVidaActual(0);
										pgMiPokemon->Value = miPokemon->getVidaActual();
									}

									pgPokemonRival->Value = pokemonRival->getVidaActual();
									btnCapturar->Visible = true;
									pgMiPokemon->Visible = true;
									pgPokemonRival->Visible = true; 

									radioButton1->Visible = true;	radioButton1->Text = gcnew String(miPokemon->getAtaque1());
									radioButton2->Visible = true;	radioButton2->Text = gcnew String(miPokemon->getAtaque2());
									radioButton3->Visible = true;	radioButton3->Text = gcnew String(miPokemon->getAtaque3());
									radioButton4->Visible = true;	radioButton4->Text = gcnew String(miPokemon->getAtaque4());
									radioButton1->Focus();
							case 3: break;
							default:dialogo = "Escoja un ataque";
									//miPokemon->quitarVida(7);
								retrasoContraAtaque->Enabled = true;
								modoRetraso = true;
									if(radioButton1->Checked == true)
										pokemonRival->quitarVida(miPokemon->getDañoAtaque1());
									else if(radioButton2->Checked == true)
										pokemonRival->quitarVida(miPokemon->getDañoAtaque2());
									else if(radioButton3->Checked == true)
										pokemonRival->quitarVida(miPokemon->getDañoAtaque3());
									else
										pokemonRival->quitarVida(miPokemon->getDañoAtaque4());
									if(pokemonRival->getVidaActual() < 10)
										btnCapturar->Enabled = true;	

									if (pokemonRival->getVidaActual() < 0)
									{
										indiceEliminar = -1;
										btnCapturar->Visible = false;
										pgMiPokemon->Visible = false;
										pgPokemonRival->Visible = false;
										panelTexto->Visible = false;
										timerMapa->Enabled = true;
										timerBatalla->Enabled = false;
										numtexto = 0;
										radioButton1->Visible = false;
										radioButton2->Visible = false;
										radioButton3->Visible = false;
										radioButton4->Visible = false;
										dialogo = "";
										juego->getPokemonEnPos(0)->setVidaActual(50);
										btnCapturar->Enabled = false;
										MessageBox::Show("Pokemon debilitado");
										//pokemonRival = juego->getPokemonEnPos(0);
										//pokemonRival->setVidaActual(pokemonRival->getVidaMaxima());
										//comenzo = 0;
									}
									if (miPokemon->getVidaActual() < 0)
									{
										indiceEliminar = -1;
										btnCapturar->Visible = false;
										pgMiPokemon->Visible = false;
										pgPokemonRival->Visible = false;
										panelTexto->Visible = false;
										timerMapa->Enabled = true;
										timerBatalla->Enabled = false;
										numtexto = 0;
										radioButton1->Visible = false;
										radioButton2->Visible = false;
										radioButton3->Visible = false;
										radioButton4->Visible = false;
										dialogo = "";
										btnCapturar->Enabled = false;
										juego->getPokemonEnPos(0)->setVidaActual(50);
										//miPokemon->setVidaActual(50);
										//CAMBIO LAS COORDENADAS DEL JUGADOR

										MessageBox::Show("Tu Pokemon esta debilitado,llevalo de emergencia al centro PKMN");
										//pokemonRival = juego->getPokemonEnPos(0);
										//pokemonRival->setVidaActual(pokemonRival->getVidaMaxima());
										//comenzo = 0;
									}

						}
					 }
				 }
				 if(timerCentroP->Enabled == true)
				 {
					 if(e->KeyData == Keys::Escape)
					 {
						 indiceEliminar = -1;
						 timerCentroP->Enabled = false;
						 timerMapa->Enabled = true;
						 btnCapturar->Visible = false;
						 pgMiPokemon->Visible = false;
						 pgPokemonRival->Visible = false;
						 panelTexto->Visible = false;
						 timerMapa->Enabled = true;
						 timerBatalla->Enabled = false;
						 numtexto = 0;
						 radioButton1->Visible = false;
						 radioButton2->Visible = false;
						 radioButton3->Visible = false;
						 radioButton4->Visible = false;
						 dialogo = "";
						 juego->getJugador()->regresarPos();
					 }
				 }
			}
private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {/*
			CObjeto *obj = new CObjeto(e->X-50,e->Y-30,100,60,2);
			juego->agregarObjeto(obj);*/

			 MessageBox::Show("X: " + e->X + "\nY: " + e->Y);
		 }
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {		

			 //gimnasio
			 x = e->X-50;
			 y = e->Y-30;
		 }
	private: System::Void btnCapturar_Click(System::Object^  sender, System::EventArgs^  e) 
			 {				 
				// juego->getJugador()->agregarPokemon(pokemonRival);
				 CPokemon*nuevo = new CPokemon(1, 1, "pikachu");
				 nuevo->setVidaActual(pokemonRival->getVidaActual());
				 nuevo->setAtaque("Ataque Basico", 5, 1);
				 nuevo->setAtaque("Impact Trueno", 10, 2);
				 nuevo->setAtaque("Embestida", 6, 3);
				 nuevo->setAtaque("Golpe Trueno", 8, 4);
				 juego->getJugador()->agregarPokemon(nuevo);

				 juego->eliminarPokemonSilvestre(indiceEliminar);

				 btnCapturar->Visible = false;
				 pgMiPokemon->Visible = false;
				 pgPokemonRival->Visible = false;
				 panelTexto->Visible = false;
				 timerMapa->Enabled = true;
				 timerBatalla->Enabled = false;				 
				 numtexto = 0;
				 radioButton1->Visible = false;
				 radioButton2->Visible = false;
				 radioButton3->Visible = false;
				 radioButton4->Visible = false;
				 dialogo = "";
				 juego->getPokemonEnPos(0)->setVidaActual(50);
				 btnCapturar->Enabled = false;
				 MessageBox::Show("Felicidades, has capturado un pokemon");
			 }
	private: System::Void retrasoContraAtaque_Tick(System::Object^  sender, System::EventArgs^  e) {

		if (retraso == 1)
		{
			miPokemon->quitarVida(7);
			retraso = 0;
			modoRetraso = false;
			retrasoContraAtaque->Enabled = false;
		}

		retraso++;

	}
};
}

/* 
 * File:   EntradaEnFacebook.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 27 de septiembre de 2015, 11:01
 */

#ifndef ENTRADAENFACEBOOK_H
#define	ENTRADAENFACEBOOK_H

#include <string>

/**
 * @brief Clase para almacenar una entrada en Facebook junto con los comentarios  de otros usuarios
 * @param texto Texto de la entrada en Facebook
 */
class EntradaEnFacebook
{
   public:
      EntradaEnFacebook ();
      EntradaEnFacebook ( int id, std::string texto , int maxComentarios );
      EntradaEnFacebook ( const EntradaEnFacebook& orig );
      virtual ~EntradaEnFacebook ();
      void SetId ( int id );
      int GetId () const;
      void SetTexto( const std::string& texto );
      std::string GetTexto () const;
      int GetMaxComentarios () const;
      int GetNumComentarios () const;
      std::string GetComentario ( int pos ) const;
      void AddComentario ( const std::string& nuevoComentario );
      
      bool operator== ( const EntradaEnFacebook& otro );
      bool operator<= ( const EntradaEnFacebook& otro );
      EntradaEnFacebook& operator= ( const EntradaEnFacebook& otro );
    
   private:
      /// Identificador de entrada
      int _id=0;
      
      /// Texto inicial de la entrada en Facebook
      std::string _texto="";
      
      /// Vector que guarda los comentarios de la gente a esta entrada
      std::string *_comentarios=nullptr;
      
      /// Máximo número de comentarios que admitimos
      int _maxComentarios=10;
      
      /// Número real de comentarios que tenemos en cada momento, siempre <=maxComentarios
      int _numComentarios=0;
};

#endif	/* ENTRADAENFACEBOOK_H */


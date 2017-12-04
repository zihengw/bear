#ifndef BEARAPP_H
#define BEARAPP_H

#include "MooseApp.h"

class bearApp;

template <>
InputParameters validParams<bearApp>();

class bearApp : public MooseApp
{
public:
  bearApp(InputParameters parameters);
  virtual ~bearApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BEARAPP_H */

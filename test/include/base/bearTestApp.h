#ifndef BEARTESTAPP_H
#define BEARTESTAPP_H

#include "MooseApp.h"

class bearTestApp;

template <>
InputParameters validParams<bearTestApp>();

class bearTestApp : public MooseApp
{
public:
  bearTestApp(InputParameters parameters);
  virtual ~bearTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BEARTESTAPP_H */

//
//  ProfileViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit

class ProfileViewController: UIViewController {
    @IBOutlet weak var emailField: UIView!
    @IBOutlet weak var userField: UIView!
    
    @IBOutlet weak var email: UILabel!
    @IBOutlet weak var user: UILabel!
    @IBOutlet weak var exitButtonEdit: DefaultButton!
    
    
    override func viewDidLoad() {
        setupFirstField()
        setupSecondField()
        setupEmailAndUser()
        exitButtonEdit.configure(whatsInside: "Sair")
    }
    
    func setupEmailAndUser() {
        email.text = UserDefaults.standard.string(forKey: "email")
        user.text = UserDefaults.standard.string(forKey: "usuario")
    }
    
    func setupFirstField() {
        emailField.layer.cornerRadius = 20
        emailField.layer.borderWidth = 0.5
        emailField.layer.borderColor = UIColor(red: 0.669, green: 0.669, blue: 0.669, alpha: 1).cgColor
    }
    
    func setupSecondField() {
        userField.layer.cornerRadius = 20
        userField.layer.borderWidth = 0.5
        userField.layer.borderColor = UIColor(red: 0.669, green: 0.669, blue: 0.669, alpha: 1).cgColor
    }
    
    @IBAction func exitButton(_ sender: Any) {
        UserDefaults.standard.set(false, forKey: "logado")
        UserDefaults.standard.set("", forKey: "usuario")
        UserDefaults.standard.set("", forKey: "email")
        let myViewController = Register2ViewController()
        self.navigationController?.pushViewController(myViewController, animated: true)
    }
}
